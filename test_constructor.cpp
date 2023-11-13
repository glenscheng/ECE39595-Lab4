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

  // act
  polynomial p;

  // print
  p.print();
}

// testing 1x^0: {0,1}
static void constant() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with a constant: 1x^0: {0,1}." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{0,1}};

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  p.print();
}

// testing 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}
static void x_plus_1_squared() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with normal powers and coeffs: 1x^2 + 2x^1 + 1x^0: {{2,1},{1,2},{0,1}}." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{2,1},{1,2},{0,1}};

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  p.print();
}

// testing 5x^5 + 2x^2: {{5,5},{4,0},{3,0},{2,2}}
static void zero_coeffs() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with zero coeffs: 5x^5 + 2x^2: {{5,5},{4,0},{3,0},{2,2}}." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{5,5},{4,0},{3,0},{2,2}};

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  p.print();
}

// testing 5x^5 - 2x^2: {{5,5},{2,-2}}
static void negative_coeff() {
  cout << "------------------------------------------" << endl;
  cout << "Starting test for constructor with negative coeffs: 5x^5 - 2x^2: {{5,5},{2,-2}}." << endl;

  // initialize
  vector<pair<power, coeff>> poly_input = {{5,5},{2,-2}};

  // act
  polynomial p(poly_input.begin(), poly_input.end());

  // print
  p.print();
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
