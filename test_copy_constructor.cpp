#include <iostream>
#include <vector>
#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


// test copy constructor with empty polynomial/map
static void empty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for copy constructor: empty polynomial/map." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  polynomial p1;

  // act
  polynomial p2(p1);

  // print
  cout << "Print p2: ";
  p2.print();
  cout << endl;

  // check that p2 is empty
  if (p2.get_poly().empty() == true) {
    passed++;
  } else {
    cout << "* * FAILED * * map is not empty" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}


// test copy constructor with nonempty polynomial/map
static void nonempty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for copy constructor: 2x^2 8x^0: {{3,0},{2,2},{0,8}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  power pwr;
  coeff exp_coeff;
  vector<pair<power, coeff>> poly_input = {{3,0},{2,2},{0,8}};
  polynomial p1(poly_input.begin(), poly_input.end());

  // act
  polynomial p2(p1);

  // print
  cout << "Print p2: ";
  p2.print();
  cout << endl;

  // check
  pwr = 3;
  exp_coeff = 0;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 2;
  exp_coeff = 2;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 8;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}


void test_copy_constructor_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting test for polynomial copy constructor" << endl;
  empty();
  nonempty();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
