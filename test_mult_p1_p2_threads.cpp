#include <iostream>
#include <vector>
#include <thread>

#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


static void CompareSequentialVsParallel(polynomial p1, polynomial p2){
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  test_mult_p1_p2_sequential(p1, p2);
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  test_mult_p1_p2_parallel_8(p1, p2);
  std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();

  double duration1 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  double duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t3 - t2 ).count();
  cout << "Execution time: Sequential: " << duration1 << " us" << ", Threads: " << duration2 << " us" << std::endl;
  cout << "Speedup: " << duration1 / duration2 << endl;
}

static void Parallel4(polynomial p1, polynomial p2){
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  test_mult_p1_p2_parallel_4(p1, p2);
  std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();

  double duration2 = std::chrono::duration_cast<std::chrono::seconds>( t3 - t2 ).count();
  cout << "Execution time: Threads: " << duration2 << " s" << std::endl;
}

static void Parallel8(polynomial p1, polynomial p2){
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  test_mult_p1_p2_parallel_8(p1, p2);
  std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();

  double duration2 = std::chrono::duration_cast<std::chrono::seconds>( t3 - t2 ).count();
  cout << "Execution time: Threads: " << duration2 << " s" << std::endl;
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

// 30x30
static void thirties() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 30x30." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
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

// 60x20
static void sixty_twenty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 60x20." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{59,1},{58,1},{57,1},{56,1},{55,1},{54,1},{53,1},{52,1},{51,1},{50,1},{49,1},{48,1},{47,1},{46,1},{45,1},{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
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

// 20x60
static void twenty_sixty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 20x60." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{59,1},{58,1},{57,1},{56,1},{55,1},{54,1},{53,1},{52,1},{51,1},{50,1},{49,1},{48,1},{47,1},{46,1},{45,1},{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
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

// 2x60
static void two_sixty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 2x60." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{59,1},{58,1},{57,1},{56,1},{55,1},{54,1},{53,1},{52,1},{51,1},{50,1},{49,1},{48,1},{47,1},{46,1},{45,1},{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{1,1},{0,1}};
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

// 15x60
static void fifteen_sixty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 15x60." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input1 = {{59,1},{58,1},{57,1},{56,1},{55,1},{54,1},{53,1},{52,1},{51,1},{50,1},{49,1},{48,1},{47,1},{46,1},{45,1},{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
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

// 60x60
static void sixties() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 60x60." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{59,1},{58,1},{57,1},{56,1},{55,1},{54,1},{53,1},{52,1},{51,1},{50,1},{49,1},{48,1},{47,1},{46,1},{45,1},{44,1},{43,1},{42,1},{41,1},{40,1},{39,1},{38,1},{37,1},{36,1},{35,1},{34,1},{33,1},{32,1},{31,1},{30,1},{29,1},{28,1},{27,1},{26,1},{25,1},{24,1},{23,1},{22,1},{21,1},{20,1},{19,1},{18,1},{17,1},{16,1},{15,1},{14,1},{13,1},{12,1},{11,1},{10,1},{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
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

// 5,000x5,000
static void fivethousands() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 5,000x5,000." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input;
  int terms = 5000;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  // p.print();
  cout << " * ";
  // p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  //cout << "4 THREADS:" << endl;
  //Parallel4(p, p);
  cout << "8 THREADS:" << endl;
  Parallel8(p, p);
}

// 25,000x25,000
static void twentyfivethousands() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 25,000x25,000." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input;
  int terms = 25000;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  // p.print();
  cout << " * ";
  // p.print();
  cout << "Total terms:" << p.get_poly().size() * p.get_poly().size() << endl << endl;
  
  // act
  //cout << "4 THREADS:" << endl;
  //Parallel4(p, p);
  cout << "8 THREADS:" << endl;
  Parallel8(p, p);
}


void test_mult_p1_p2_threads_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting timing test for threads for polynomial * polynomial" << endl;
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
  thirties();
  sixty_twenty();
  twenty_sixty();
  two_sixty();
  fifteen_sixty();
  sixties();
  fivethousands();
  twentyfivethousands();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
