#include <iostream>
#include <vector>
#include <thread>

#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


static void CompareSequentialVsParallel(polynomial p, int c){
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  test_mult_p_int_sequential(p, c);
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  test_mult_p_int_parallel_4(p, c);
  std::chrono::steady_clock::time_point t3 = std::chrono::steady_clock::now();

  double duration1 = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  double duration2 = std::chrono::duration_cast<std::chrono::microseconds>( t3 - t2 ).count();
  cout << "Execution time: Sequential: " << duration1 << " us" << ", Threads: " << duration2 << " us" << std::endl;
  cout << "Speedup: " << duration1 / duration2 << endl;
}

// 0 terms
static void zero() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 0 terms." << endl;

  // initialize
  int c = 2;
  polynomial p;

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 1 terms
static void one() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 1 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input = {{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 10 terms
static void ten() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 10 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input = {{9,1},{8,1},{7,1},{6,1},{5,1},{4,1},{3,1},{2,1},{1,1},{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 50 terms
static void fifty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 50 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input;
  int terms = 50;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 100 terms
static void onehundred() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 100 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input;
  int terms = 100;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 500 terms
static void fivehundred() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 500 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input;
  int terms = 500;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  // p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 1,000 terms
static void onethousand() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 1,000 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input;
  int terms = 1000;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  // p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

// 10,000 terms
static void tenthousand() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 10,000 terms." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input;
  int terms = 10000;
  for (int i = 0; i < terms; i++) {
    poly_input.push_back({i,1});
  }
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  // p.print();
  cout << " * ";
  cout << c << endl;
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

void test_mult_p_int_threads() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting timing test for threads for polynomial * int" << endl;
  zero();
  one();
  ten();
  fifty();
  onehundred();
  fivehundred();
  onethousand();
  //tenthousand();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
