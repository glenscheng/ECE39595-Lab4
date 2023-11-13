#include <iostream>
#include <vector>
#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;


// test assignment operator with empty polynomial/map
static void empty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for assignment operator: empty polynomial/map." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  polynomial p1;

  // act
  polynomial p2 = p1;

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

// test assignment operator with nonempty polynomial
static void nonempty() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for assignment operator: p2 = p1 with 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  power pwr;
  coeff exp_coeff;
  vector<pair<power, coeff>> poly_input = {{2,1},{1,2},{0,1}};
  polynomial p1(poly_input.begin(), poly_input.end());

  // act
  polynomial p2 = p1;

  // print
  cout << "Print p2: ";
  p2.print();
  cout << endl;

  // check coeffs
  pwr = 2;
  exp_coeff = 1;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 1;
  exp_coeff = 2;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 1;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// test assignment operator with nonempty polynomial/map and checking if we can change values
static void change() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for assignment operator: testing change with 2x^2 8x^0: {{3,0},{2,2},{0,8}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{3,0},{2,2},{0,8}};
  polynomial p1(poly_input.begin(), poly_input.end());
  polynomial p2;
  p2 = p1;

  // print
  cout << "Before clearing p2:" << endl;
  cout << "Print old p1: ";
  p1.print();
  cout << "Print old p2: ";
  p2.print();
  cout << endl;

  // act
  p2.clear_poly();

  // print
  cout << "After clearing p2:" << endl;
  cout << "Print new p1: ";
  p1.print();
  cout << "Print new p2: ";
  p2.print();
  cout << endl;

  // check that only p2 map is empty 
  if (p2.get_poly().empty() == true) {
    passed++;
  } else {
    cout << "* * FAILED * * map is not empty" << endl;
  }
  num_tests++;
  if (p1.get_poly().empty() == false) {
    passed++;
  } else {
    cout << "* * FAILED * * map is not empty" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// test assignment operator with chaining
static void chain() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for assignment operator: p3 = p2 = p1 with 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  power pwr;
  coeff exp_coeff;
  vector<pair<power, coeff>> poly_input = {{2,1},{1,2},{0,1}};
  polynomial p1(poly_input.begin(), poly_input.end());
  polynomial p2;
  polynomial p3;

  // act
  p3 = p2 = p1;

  // print
  cout << "Print p2: ";
  p2.print();
  cout << "Print p3: ";
  p3.print();
  cout << endl;

  // check coeffs for p2
  pwr = 2;
  exp_coeff = 1;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 1;
  exp_coeff = 2;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 1;
  if (p2.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  // check coeffs for p3
  pwr = 2;
  exp_coeff = 1;
  if (p3.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 1;
  exp_coeff = 2;
  if (p3.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 1;
  if (p3.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// test assignment operator with self assignment
static void self() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for assignment operator: p1 = p1 with 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  power pwr;
  coeff exp_coeff;
  vector<pair<power, coeff>> poly_input = {{2,1},{1,2},{0,1}};
  polynomial p1(poly_input.begin(), poly_input.end());

  // act
  p1 = p1;

  // print
  cout << "Print p1: ";
  p1.print();
  cout << endl;

  // check coeffs
  pwr = 2;
  exp_coeff = 1;
  if (p1.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 1;
  exp_coeff = 2;
  if (p1.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  pwr = 0;
  exp_coeff = 1;
  if (p1.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}


void test_assignment_operator_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting test for polynomial assignment operator" << endl;
  empty();
  nonempty();
  change();
  chain();
  self();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
