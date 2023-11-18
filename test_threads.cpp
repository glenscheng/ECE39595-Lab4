#include <iostream>
#include <vector>
#include <thread>

#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


/*
// Function for threading
static void multiply_terms(power this_power, coeff this_coeff, power other_power, coeff other_coeff, polynomial &temp) {
  temp.insert_poly(this_power + other_power, this_coeff * other_coeff);
}
static void multiply_terms_4(map<power, coeff> this_vals, map<power, coeff> other_vals, polynomial &temp) {
  // Iterate through all the terms in the first polynomial 
  auto this_end = this_vals.rend();
  auto other_end = other_vals.rend();
  for (auto this_iter = this_vals.rbegin(); this_iter != this_end; this_iter++) {
    polynomial t;
    // Iterate through all the terms in the second polynomial
    for (auto other_iter = other_vals.rbegin(); other_iter != other_end; other_iter++) {
      t.insert_poly((*this_iter).first + (*other_iter).first, (*this_iter).second * (*other_iter).second);
    }
    temp = temp + t;
  }
}

polynomial test_multiply_parallel_4(polynomial p1, polynomial p2) {
  // PARALLEL (threads = 4)
  polynomial zero;
  int size = 4; // using only 4 threads
  int this_terms_per_thread = p1.poly.size() / size;
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // create vectors for powers and coeffs for `other`
  map<power, coeff> other_vals1;
  map<power, coeff> other_vals2;
  map<power, coeff> other_vals3;
  map<power, coeff> other_vals4;
  auto other_end = p2.poly.rend();
  for (auto other_iter = p2.poly.rbegin(); other_iter != other_end; other_iter++) {
    power other_power = (*other_iter).first;
    coeff other_coeff = (*other_iter).second;
    other_vals1.insert({other_power, other_coeff});
    other_vals2.insert({other_power, other_coeff});
    other_vals3.insert({other_power, other_coeff});
    other_vals4.insert({other_power, other_coeff});
  }

  // create vectors for powers and coeffs for `this` / 4
  auto this_iter = p1.poly.rbegin();
  auto this_end = p1.poly.rend();
  // for 1st thread:
  map<power, coeff> this_vals1;
  int i = 0;
  while (i < this_terms_per_thread) {
    this_vals1.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 2nd thread:
  map<power, coeff> this_vals2;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals2.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 3rd thread:
  map<power, coeff> this_vals3;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals3.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 4th thread:
  map<power, coeff> this_vals4;
  while (this_iter != this_end) {
    this_vals4.insert({(*this_iter).first, (*this_iter).second});
    this_iter++;
  }

  // initialize threads vector AND call threads
  vector<thread> threads;
  i = 0;
  threads.push_back(thread(multiply_terms_4, this_vals1, other_vals1, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals2, other_vals2, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals3, other_vals3, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(multiply_terms_4, this_vals4, other_vals4, ref(temps.at(i))));
  threads.at(i);

  // wait for threads to finish
  for (int i = 0; i < size; i++) {
    threads.at(i).join();
  }

  // sum temps for result
  polynomial result;
  for (polynomial p : temps) {
    result = result + p;
  }

  return result;
}

polynomial test_multiply_sequential(polynomial p1, polynomial p2) {
  // SEQUENTIAL
  polynomial result;

  // Iterate through all the terms in the first polynomial 
  for (auto p1_iter = p1.poly.begin(); p1_iter != p1.poly.end(); p1_iter++) {

    // Temporary polynomial for individual sums 
    polynomial temp;

    // Iterate through all the terms in the second polynomial
    for (auto p2_iter = p2.poly.begin(); p2_iter != p2.poly.end(); p2_iter++) {
      temp.poly[(p1_iter -> first) + (p2_iter -> first)] = (p1_iter -> second) * (p2_iter -> second);
    }

    result = result + temp;
  }

  return result;
}
*/

static void CompareSequentialVsParallel(polynomial p1, polynomial p2){
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  test_multiply_sequential(p1, p2);
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  test_multiply_parallel_4(p1, p2);
  std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();

  double duration1 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  double duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t3 - t2 ).count();
  cout << "Execution time: Sequential: " << duration1 << ", Threads: " << duration2 << std::endl;
  cout << "Speedup: " << duration1 / duration2 << endl;
}

// 1x1 terms
static void ones() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 1x1." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 2x2 terms
static void twos() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 2x2." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 3x3 terms
static void threes() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 3x3." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 4x4 terms
static void fours() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 4x4." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 5x5 terms
static void fives() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 5x5." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 6x6 terms
static void sixes() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 6x6." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 7x7 terms
static void sevens() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 7x7." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 8x8 terms
static void eights() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 8x8." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 9x9 terms
static void nines() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 9x9." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 10x10 terms
static void tens() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 10x10." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, p);
}

// 5x20 terms
static void five_twenty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 5x20." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p1.print();
  cout << " * ";
  p2.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p1, p2);
}

// 20x5 terms
static void twenty_five() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 20x5." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 30x5 terms
static void thirty_five() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 30x5." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 4x1 terms
static void four_one() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 4x1." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p1.print();
  cout << " * ";
  p2.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p1, p2);
}

// 24x4 terms
static void twentyfour_four() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x4." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 24x6 terms
static void twentyfour_six() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x6." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 24x8 terms
static void twentyfour_eight() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x8." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 30x10 terms
static void thirty_ten() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 30x10." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 45x15 terms
static void fortyfive_fifteen() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 45x15." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 45x9 terms
static void fortyfive_nine() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 45x9." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 45x5 terms
static void fortyfive_five() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 45x5." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 24x2 terms
static void twentyfour_two() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x2." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 24x1 terms
static void twentyfour_one() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x1." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

// 24x0 terms
static void twentyfour_zero() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 24x0." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input2 = {{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p1;
  polynomial p2(poly_input2.begin(), poly_input2.end());

  // print 
  cout << "Multiplying: ";
  p2.print();
  cout << " * ";
  p1.print();
  cout << "Total terms:" << p1.get_poly().size() * p2.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p2, p1);
}

void test_threads_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting timing test for threads" << endl;
  ones();
  twos();
  threes();
  fours();
  fives();
  sixes();
  sevens();
  eights();
  nines();
  tens();
  five_twenty();
  twenty_five();
  thirty_five();
  four_one();
  twentyfour_four();
  twentyfour_six();
  twentyfour_eight();
  thirty_ten();
  fortyfive_fifteen();
  fortyfive_nine();
  fortyfive_five();
  twentyfour_two();
  twentyfour_one();
  twentyfour_zero();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
