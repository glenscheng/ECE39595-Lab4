#include <iostream>
#include <vector>

#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


// testing that no argument constructor creates polynomial 0x^0
static void no_arg() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for empty constructor: no argument." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;

  // act
  polynomial p;

  // print
  cout << "Print: ";
  p.print();
  cout << endl;

  // check 
  if (p.get_poly().empty() == true) {
    passed++;
  } else {
    cout << "* * FAILED * * map is not empty" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// testing 1x^0: {0,1}
static void constant() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with a constant: 1x^0: {0,1}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{0,1}};
  power pwr;
  coeff exp_coeff;

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  cout << "Print: ";
  p.print();
  cout << endl;

  // check
  pwr = 0;
  exp_coeff = 1;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// testing 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}
static void x_plus_1_squared() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with normal powers and coeffs: 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{2,1},{1,2},{0,1}};
  power pwr;
  coeff exp_coeff;

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  cout << "Print: ";
  p.print();
  cout << endl;

  // check
  pwr = 2;
  exp_coeff = 1;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 1;
  exp_coeff = 2;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 1;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// testing 5x^5 + 2x^2: {{5,5},{4,0},{3,0},{2,2}}
static void zero_coeffs() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with zero coeffs: 5x^5 + 2x^2: {{5,5},{4,0},{3,0},{2,2}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{5,5},{4,0},{3,0},{2,2}};
  power pwr;
  coeff exp_coeff;

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  cout << "Print: ";
  p.print();
  cout << endl;

  // check
  pwr = 5;
  exp_coeff = 5;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 4;
  exp_coeff = 0;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 3;
  exp_coeff = 0;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 2;
  exp_coeff = 2;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// testing 5x^5 - 2x^2: {{5,5},{2,-2}}
static void negative_coeff() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with negative coeffs: 5x^5 - 2x^2: {{5,5},{2,-2}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{5,5},{2,-2}};
  power pwr;
  coeff exp_coeff;

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  cout << "Print: ";
  p.print();
  cout << endl;

  // check
  pwr = 5;
  exp_coeff = 5;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 2;
  exp_coeff = -2;
  if (p.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}


void test_constructor_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting test for polynomial constructors" << endl;
  no_arg();
  constant();
  x_plus_1_squared();
  zero_coeffs();
  negative_coeff();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
