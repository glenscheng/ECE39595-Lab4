#include <map>
#include <vector>
#include <thread>
#include "poly.h"

using std::vector;
using std::map;
using std::thread;
using std::ref;

// Construct a new polynomial object that is the number 0 (ie. 0x^0)
polynomial::polynomial(void) {} // stay as empty map

// Copy constructor 
polynomial::polynomial(const polynomial &other) {
  // Initialize and fill new map w/ `other` polynomial
  map<power, coeff> new_poly(other.poly);

  // Copy map to `this` polynomial
  poly = new_poly;
}

// Assignment operator 
polynomial& polynomial::operator=(const polynomial &other) {
  // Initialize and fill new map w/ `other` polynomial
  map<power, coeff> new_poly(other.poly);

  // Copy map to `this` polynomial
  poly = new_poly;

  return *this;
}

// Returns a vector that contains the polynomial is canonical form
std::vector<std::pair<power, coeff>> polynomial::canonical_form() const {

  std::vector<std::pair<power, coeff>> result; // Vector containing power and coefficient pairs

  // Iterate through the polynomial starting from the highest degree
  for (auto Iter = (this -> poly).rbegin(); Iter != (this -> poly).rend(); Iter++) {
    result.push_back(*Iter);
  }

  // If there are no terms in the polynomial, then add (0,0)
  if ((this -> poly).empty()) {
    result.push_back(std::pair<power, coeff>(0, 0));
  }

  return result;
}

// Returns the degree of the polynomial
size_t polynomial::find_degree_of() const {
  if (!((this -> poly).empty())) {
    return (this -> poly).rbegin() -> first; 
  } else {
    return 0;
  }
}

// Prints the polynomial
void polynomial::print() const {

  for (auto p = (this -> poly).rbegin(); p != (this -> poly).rend(); p++) {
    int pow = p -> first;
    int cof = p -> second;
    std::cout << "(" << cof << "x^" << pow << ") + ";  
  }

  std::cout << std::endl;

}

// Adds two polynomials (polynomial + polynomial) and returns the result
polynomial polynomial::operator+(const polynomial& other) const {

  polynomial result;

  // Initialize pointers to both of the polynomials
  auto p = (this -> poly).rbegin();
  auto q = other.poly.rbegin();
  auto p_end = (this -> poly).rend();
  auto q_end = other.poly.rend();

  // Iterate through both of the polynomials and add up the terms
  while (p != p_end || q != q_end) {

    // Check if reached the end of one of the polynomials
    if (p == p_end) {
      result.poly.insert(std::pair<power, coeff>(q -> first, q -> second));
      q++;
    } else if (q == q_end) {
      result.poly.insert(std::pair<power, coeff>(p -> first, p -> second));
      p++;

      // Check if there are terms corresponding to the current degree in both of the polynomials
    } else if ((p -> first) == (q -> first)) {

      // Don't add zero terms
      if ((p -> second) + (q -> second) != 0) {
        result.poly.insert(std::pair<power, coeff>(p -> first, (p -> second) + (q -> second)));
      }
      p++;
      q++;

      // Insert the higer degree power first
    } else if (p -> first > q -> first) {
      result.poly.insert(std::pair<power, coeff>(p -> first, p -> second));
      p++;
    } else {
      result.poly.insert(std::pair<power, coeff>(q -> first, q -> second));
      q++;
    }

  }

  return result;
}

// Adds a polynomial and a number (polynomial + int) and returns the result
polynomial polynomial::operator+(const int i) const {

  // Create a copy of the current polynomial
  polynomial result = *this; 

  size_t pow = 0;

  // Add the constant to the polynomial
  if (result.poly.find(pow) != result.poly.end()) {
    // Don't add zero terms
    if (result.poly[pow] + i != 0) {
      result.poly[pow] = result.poly[pow] + i;
    } else {
      result.poly.erase(pow);
    }
  } else {
    // Don't add zero terms
    if (i != 0) {
      result.poly[pow] = i;
    }
  }

  return result;
}

// Adds a number and a polynomial (int + polynomial) and returns the result
polynomial operator+(const int i, const polynomial& polynomial_object) {

  // Create a copy of the current polynomial
  polynomial result = polynomial_object; 

  size_t pow = 0;

  // Add the constant to the polynomial
  if (result.poly.find(pow) != result.poly.end()) {
    // Don't add zero terms
    if (result.poly[pow] + i != 0) {
      result.poly[pow] = result.poly[pow] + i;
    } else {
      result.poly.erase(pow);
    }
  } else {
    // Don't add zero terms
    if (i != 0) {
      result.poly[pow] = i;
    }
  }

  return result;
}

// Multiplies a polynomial and a number (polynomial * int) and returns the result
polynomial polynomial::operator*(const int i) const {

  polynomial result;

  // Don't add zero terms
  if (i != 0) {
    for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {
      result.poly.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
    }
  }


  return result;
}

// Multiplies a polynomial and a number (polynomial * int) and returns the result
polynomial operator*(const int i, const polynomial& polynomial_object) { 

  polynomial result;

  // Don't add zero terms
  if (i != 0) {
    for (auto iter = polynomial_object.poly.begin(); iter != polynomial_object.poly.end(); iter++) {
      result.poly.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
    }
  }

  return result;
}

static void multiply_term(power curr_power, coeff curr_coeff, const polynomial other, polynomial &temp, int k) {
  for (auto other_iter = other.get_poly().begin(); other_iter != other.get_poly().end(); other_iter++) {
    temp.get_poly()[curr_power + (other_iter -> first)] = curr_coeff * (other_iter -> second);
  }
}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {
  polynomial zero;
  int size = this->poly.size();
  vector<polynomial> temps(size);

  // initialize temps vector
  for (int i = 0; i < size; i++) {
    temps.at(i) = zero;
  }

  int k = 1;

  // initialize threads vector AND call threads
  vector<thread> threads;
  int i = 0;
  for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {
    threads.push_back(thread(multiply_term, iter->first, iter->second, other, ref(temps.at(i)), k));
    threads.at(i);
    i++;
  }

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

/*
  polynomial result;

  // Iterate through all the terms in the first polynomial 
  for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {

    // Temporary polynomial for individual sums 
    polynomial temp;

    // Iterate through all the terms in the second polynomial
    for (auto other_iter = other.poly.begin(); other_iter != other.poly.end(); other_iter++) {
      temp.poly[(iter -> first) + (other_iter -> first)] = (iter -> second) * (other_iter -> second);
    }

    result = result + temp;
  }

  return result;
*/

}

// Finds the modulo of a polynomial and another polynomial (polynomial * int) and returns the result
polynomial polynomial::operator%(const polynomial& other) const {

  // Create a copy of the current polynomial
  polynomial result = *this;
  polynomial divisor = other;

  // Do the long division
  while (other.find_degree_of() <= result.find_degree_of()) {
    int result_degree = result.find_degree_of();
    int divisor_degree = divisor.find_degree_of();
    int multiplication_constant = result.poly[result_degree] / divisor.poly[divisor_degree];
    int multiplication_power = result_degree - divisor_degree;
    std::vector<std::pair<power, coeff>> multiplication_polynomial_terms = {{multiplication_power, multiplication_constant}};
    polynomial multiplication_polynomial = polynomial(multiplication_polynomial_terms.begin(), multiplication_polynomial_terms.end());
    result = result + (-1 * (other * multiplication_polynomial));
  }

  return result;
}
// Test method to determine if coeff is correct at a specific power
bool polynomial::check_coeff(power pwr, coeff exp_c) {
  // Check that 0 coefficient means that term is not in map
  if (exp_c == 0 && poly.count(pwr) != 0) {
    return false;
  }
  if (exp_c == 0 && poly.count(pwr) == 0) {
    return true;
  }

  // Check that power is in polynomial
  if (poly.count(pwr) != 1) {
    return false;
  }
  // Check if expected coeff == actual coeff
  if (exp_c != poly.at(pwr)) {
    return false;
  }
  return true;
}
