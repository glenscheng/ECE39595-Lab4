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
  cout << "Execution time: Sequential: " << duration1 << ", Threads: " << duration2 << std::endl;
  cout << "Speedup: " << duration1 / duration2 << endl;
}

// 1 term
static void one() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for threads: 1." << endl;

  // initialize
  int c = 2;
  vector<pair<power, coeff>> poly_input = {{0,1}};
  polynomial p(poly_input.begin(), poly_input.end());

  // print 
  cout << "Multiplying: ";
  cout << c << endl;
  cout << " * ";
  p.print();
  cout << "Total terms:" << p.get_poly().size() << endl << endl;
  
  // act
  CompareSequentialVsParallel(p, c);
}

void test_mult_p_int_threads() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting timing test for threads for polynomial * int" << endl;
  one();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
