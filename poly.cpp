#include <unordered_map>
#include <vector>
#include <thread>
#include <iostream>
#include <algorithm>
#include "poly.h"

using std::vector;
using std::unordered_map;
using std::thread;
using std::ref;
using std::cout;
using std::endl;

// Construct a new polynomial object that is the number 0 (ie. 0x^0)
polynomial::polynomial(void) {} // stay as empty map

// Copy constructor for building a new polynomial from an old one
polynomial::polynomial(const polynomial &other) {
  this -> poly = other.poly;
}

// Assignment operator for assigning the current polynomial to a new polynomial
polynomial& polynomial::operator=(const polynomial &other) {
  this -> poly = other.poly;
  return *this;
}

// Returns a vector that contains the polynomial is canonical form
std::vector<std::pair<power, coeff>> polynomial::canonical_form() const {

  std::vector<std::pair<power, coeff>> result; // Vector containing power and coefficient pairs

  // Get the keys of the map in sorted order
  std::vector<power> keys;
  for(auto Iter = poly.begin(); Iter != poly.end(); Iter++) {
    keys.push_back(Iter -> first);
  }
  std::sort(keys.begin(), keys.end(), std::greater<power>());

  // Insert the polynomial terms in the result
  for(auto Iter = keys.begin(); Iter != keys.end(); Iter++) {
    result.push_back({*Iter, poly.at(*Iter)});
  }

  // If there are no terms in the polynomial, then add (0,0)
  if ((this -> poly).empty()) {
    result.push_back({0, 0});
  }

  return result;
}

// Returns the degree of the polynomial
size_t polynomial::find_degree_of() const {

  // If the polynomial is not empty, then return the degree 
  // of the highest degree term in the polynomial
  if (!((this -> poly).empty())) {

    // Get the keys of the map in sorted order
    std::vector<power> keys;
    for(auto Iter = poly.begin(); Iter != poly.end(); Iter++) {
    keys.push_back(Iter -> first);
    }
    std::sort(keys.begin(), keys.end(), std::greater<power>());

    return *(keys.begin()); 

  // If there are no terms, then return 0
  } else {
    return 0;
  }

}

// Prints the polynomial in a a1x^n + a2x^n-1 + ... + a0 form
void polynomial::print() const {

  // Get the keys of the map in sorted order
  std::vector<power> keys;
  for(auto Iter = poly.begin(); Iter != poly.end(); Iter++) {
    keys.push_back(Iter -> first);
  }
  std::sort(keys.begin(), keys.end(), std::greater<power>());
  
  // Iterate through all the degrees in sorted order
  for (power p : keys) {
    int pow = p;
    int cof = (this -> poly).at(p);
    std::cout << "(" << cof << "x^" << pow << ") + ";  
  }

  std::cout << std::endl;

}

// Adds two polynomials (polynomial + polynomial) and returns the result
polynomial polynomial::operator+(const polynomial& other) const {

  // Initialize the result to be the same as the current polynomial
  polynomial result = *this;

  // Iterate through all the terms in the other polynomial and add up
  // the coefficients corresponding to the terms
  for(auto element : other.poly) {

    // Check whether the term already exists in the result. If so, then
    // add up the coefficients. Otherwise, create a new term
    if (result.poly.find(element.first) != result.poly.end()) {

      // Don't add zero terms
      if (result.poly.at(element.first) + element.second != 0) {
        result.poly.at(element.first) += element.second;
      } else {
        result.poly.erase(element.first);
      }
      
    } else {
      result.poly[element.first] = element.second;
    }

  }

  return result;
}

// Subtracts two polynomials (polynomial - polynomial) and returns the result
polynomial polynomial::operator-(const polynomial& other) const {

  // Initialize the result to be the same as the current polynomial
  polynomial result = *this;

  // Iterate through all the terms in the other polynomial and add up
  // the coefficients corresponding to the terms
  for(auto element : other.poly) {

    // Check whether the term already exists in the result. If so, then
    // add up the coefficients. Otherwise, create a new term
    if (result.poly.find(element.first) != result.poly.end()) {

      // Don't add zero terms
      if (result.poly.at(element.first) - element.second != 0) {
        result.poly.at(element.first) -= element.second;
      } else {
        result.poly.erase(element.first);
      }
      
    } else {
      result.poly[element.first] = -1 * element.second;
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

  if ((this -> poly).empty() == true) {
    return result;
  }

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

  if (polynomial_object.poly.empty() == true) {
    return result;
  }

  // Don't add zero terms
  if (i != 0) {
    for (auto iter = polynomial_object.poly.begin(); iter != polynomial_object.poly.end(); iter++) {
      result.poly.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
    }
  }

  return result;
}

// Free function that multiplies two polynomials in a sequential fashion
void SequentialMultiply(const std::vector<std::pair<power, coeff>>& p1, const polynomial& p2, polynomial& res) {
	
  polynomial result;

  // Perform mutliplication using the distributive property
	// Iterate through all the terms in the first polynomial 
	for (auto iter = p1.begin(); iter != p1.end(); iter++) {

		// Iterate through all the terms in the second polynomial
		for (auto other_iter = p2.poly.begin(); other_iter != p2.poly.end(); other_iter++) {
			result.poly[(iter -> first) + (other_iter -> first)] += (iter -> second) * (other_iter -> second);
		}

	}

	res = result;

}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {

  polynomial result;                                                               // Resulting polynomial after performing the multiplication operation
  std::vector<polynomial> threads_results(num_threads);                            // Vector containing the results from each thread
  std::vector<std::vector<std::pair<power, coeff>>> threads_p1_terms(num_threads); // Vector containing the first polynomials in the multiplication of each thread
  std::vector<polynomial> threads_p2(num_threads);                                 // Vector containing the second polynomials in the multiplication of each thread
  std::vector<thread> threads;                                                     // Threads to perform sequential multiplication
  auto largest_poly_begin = (this -> poly).begin();                                // Polynomial with the most number of terms
  auto largest_poly_end = (this -> poly).end();                                    // Polynomial with the most number of terms  

  // Find the polynomial with the most number of terms
  int p1_size = (this -> poly).size(); // Number of terms in polynomial 1
  int p2_size = other.poly.size();     // Number of terms in polynomial 2
  if (p1_size >= p2_size) {
    for(int i = 0; i < num_threads; i++) {
      threads_p2[i] = other;
    }
  } else {
    largest_poly_begin = other.poly.begin();
    largest_poly_end = other.poly.end();
    for(int i = 0; i < num_threads; i++) {
      threads_p2[i] = *this;
    }
  }

  // Divide the polynomial with the largest number of terms into n threads
  int thread_no = 0;
  while (largest_poly_begin != largest_poly_end) {

    // Insert a term in the polynomial of each thread
    threads_p1_terms[thread_no % num_threads].push_back(*largest_poly_begin);
    largest_poly_begin++;
    thread_no++;
  }

  // Perform sequential multiplication in 4 threads
  for (int i = 0; i < num_threads; i++) {
    threads.push_back(thread(SequentialMultiply, threads_p1_terms[i], threads_p2[i], std::ref(threads_results[i])));
  }

  // Wait for the 4 threads to finish
  for (int i = 0; i < num_threads; i++) {
    threads[i].join();
  }

  // Add up the results from each thread
  for (int i = 0; i < num_threads; i++) {
    result = result + threads_results[i];
  }

  return result;
}

// Multiplies two polynomials where polynomial 1 is of the form ax^n and polynomial 2 is of the form b1x^m + b2x^m-1 + ... + b0 
polynomial SequentialMultiplySingleTerm(const std::pair<power, coeff>& poly_term, const polynomial& poly2) {
  
  polynomial result; // Result of performing multiplication

  // Use the distributive property to multiply the polynomials
  for (auto term : poly2.poly) {
    result.poly[poly_term.first + term.first] = term.second * poly_term.second;
  }

  return result;
}

// Finds the modulo of a polynomial and another polynomial (polynomial % polynomial) and returns the result
polynomial polynomial::operator%(const polynomial& other) const {

  // Create a copy of the current polynomial
  polynomial result = *this;
  polynomial divisor = other;
  power divisor_degree = divisor.find_degree_of();

  // Do the long division
  while (divisor_degree <= result.find_degree_of()) {

    // Find the degree of the current polynomial
    int result_degree = result.find_degree_of();

    // Get the mutliplication constant and degree
    int multiplication_constant = result.poly[result_degree] / divisor.poly[divisor_degree];
    int multiplication_power = result_degree - divisor_degree;

    // Multiply the polynomial by the divisor and subtract from the result
    result = result - SequentialMultiplySingleTerm({multiplication_power, multiplication_constant}, other);

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