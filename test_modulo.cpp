#include <iostream>
#include <vector>

#include "poly.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;

// p % p = 0
static void simple() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for modulo: 2x mod 2x = 0." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input = {{1,2}};
  polynomial p(poly_input.begin(), poly_input.end());
  power pwr;
  coeff exp_coeff;

  // act
  polynomial result = p % p;

  // print
  cout << "Print result: ";
  result.print();
  cout << endl;

  // check that result = 0
  pwr = 0;
  exp_coeff = 0;
  if (result.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}

// p1 % p2 != 0
static void complex1() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for modulo: 4x^4 + 6x^2 + 8x + 1 mod 2x = 0." << endl;

  // initialize
  int passed = 0;
  int num_tests = 0;
  vector<pair<power, coeff>> poly_input1 = {{4,4},{2,6},{1,8},{0,1}};
  vector<pair<power, coeff>> poly_input2 = {{1,2}};
  polynomial p1(poly_input1.begin(), poly_input1.end());
  polynomial p2(poly_input2.begin(), poly_input2.end());
  power pwr;
  coeff exp_coeff;
  
  // act
  polynomial result = p1 % p2;

  // print
  cout << "Print result: ";
  result.print();
  cout << endl;

  // check that result = 1
  pwr = 0;
  exp_coeff = 1;
  if (result.check_coeff(pwr, exp_coeff) == true) {
    passed++;
  } else {
    cout << "* * FAILED * * coeff of power " << pwr << "is incorrect" << endl;
  }
  num_tests++;

  cout << "\033[0;32mPassed\033[0m (" << passed << "/" << num_tests << ")" << endl;
}




void test_modulo_main() {
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "Starting test for modulo" << endl;
  simple();
  complex1();
  cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
}
