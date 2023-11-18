#include <map>
#include <vector>
#include <thread>
#include <iostream>
#include "poly.h"

using std::vector;
using std::map;
using std::thread;
using std::ref;
using std::cout;
using std::endl;

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

// Function for threading
//static void multiply_terms(power this_power, coeff this_coeff, power other_power, coeff other_coeff, polynomial &temp) {
//  temp.insert_poly(this_power + other_power, this_coeff * other_coeff);
//}
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

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {

  // PARALLEL (threads = 4)
  polynomial zero;
  int size = 4; // using only 4 threads
  int this_terms_per_thread = (*this).poly.size() / size;
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // create vectors for powers and coeffs for `other`
  map<power, coeff> other_vals1;
  map<power, coeff> other_vals2;
  map<power, coeff> other_vals3;
  map<power, coeff> other_vals4;
  auto other_end = other.poly.rend();
  for (auto other_iter = other.poly.rbegin(); other_iter != other_end; other_iter++) {
    power other_power = (*other_iter).first;
    coeff other_coeff = (*other_iter).second;
    other_vals1.insert({other_power, other_coeff});
    other_vals2.insert({other_power, other_coeff});
    other_vals3.insert({other_power, other_coeff});
    other_vals4.insert({other_power, other_coeff});
  }

  // create vectors for powers and coeffs for `this` / 4
  auto this_iter = (*this).poly.rbegin();
  auto this_end = (*this).poly.rend();
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
  
/*
  // PARALLEL (threads = num terms)
  polynomial zero;
  int size = (*this).poly.size() * other.poly.size();
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // initialize threads vector AND call threads
  vector<thread> threads;
  int i = 0;
  auto this_end = (*this).poly.rend();
  auto other_end = other.poly.rend();
  for (auto this_iter = (*this).poly.rbegin(); this_iter != this_end; this_iter++) {
    for (auto other_iter = other.poly.rbegin(); other_iter != other_end; other_iter++) {
      power this_power = (*this_iter).first;
      coeff this_coeff = (*this_iter).second;
      power other_power = (*other_iter).first;
      coeff other_coeff = (*other_iter).second;
      // cout << "(before calling threads) this: " << this_coeff << "x^" << this_power << ", other: " << other_coeff << "x^" << other_power << endl;
      threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(temps.at(i))));
      //threads.push_back(thread(multiply_terms, this_power, this_coeff, other_power, other_coeff, ref(result)));
      threads.at(i);
      i++;
    }
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
*/

/*  // SEQUENTIAL
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

// Finds the modulo of a polynomial and another polynomial (polynomial % polynomial) and returns the result
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


polynomial test_multiply_parallel_4(polynomial p1, polynomial p2) {
  polynomial zero;
  if (p1.poly.empty() == true || p2.poly.empty() == true) {
    return zero;
  }

  // PARALLEL (threads = 4)
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
  polynomial zero;
  if (p1.poly.empty() == true || p2.poly.empty() == true) {
    return zero;
  }

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

