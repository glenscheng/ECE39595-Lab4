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

// Copy constructor 
polynomial::polynomial(const polynomial &other) {
  this -> poly = other.poly;
}

// Assignment operator 
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

  if (!((this -> poly).empty())) {

    // Get the keys of the map in sorted order
    std::vector<power> keys;
    for(auto Iter = poly.begin(); Iter != poly.end(); Iter++) {
    keys.push_back(Iter -> first);
    }
    std::sort(keys.begin(), keys.end(), std::greater<power>());

    return *(keys.begin()); 
  } else {
    return 0;
  }
}

// Prints the polynomial
void polynomial::print() const {

  // Get the keys of the map in sorted order
  std::vector<power> keys;
  for(auto Iter = poly.begin(); Iter != poly.end(); Iter++) {
    keys.push_back(Iter -> first);
  }
  std::sort(keys.begin(), keys.end(), std::greater<power>());
  
  for (size_t p : keys) {
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

// Functions for threading
static void mult_p1_p2_4(unordered_map<power, coeff> this_vals, unordered_map<power, coeff> other_vals, polynomial &temp) {
  // Iterate through all the terms in the first polynomial 
  auto this_end = this_vals.end();
  auto other_end = other_vals.end();
  for (auto this_iter = this_vals.begin(); this_iter != this_end; this_iter++) {
    polynomial t;
    // Iterate through all the terms in the second polynomial
    for (auto other_iter = other_vals.begin(); other_iter != other_end; other_iter++) {
      power new_power = (*this_iter).first + (*other_iter).first;
      coeff new_coeff = (*this_iter).second * (*other_iter).second;
      if (new_coeff == 0) {
        continue;
      }
      t.insert_poly(new_power, new_coeff);
    }
    temp = temp + t;
  }
}
static void mult_p_int_4(unordered_map<power, coeff> this_vals, const int i, polynomial &temp) {
  // Iterate through all the terms in the polynomial 
  auto this_end = this_vals.end();
  for (auto this_iter = this_vals.begin(); this_iter != this_end; this_iter++) {
    polynomial t;
    t.insert_poly((*this_iter).first, (*this_iter).second * i);
    temp = temp + t;
  }
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

/* rajit's threads helper function
// Free function that multiplies two polynomials in a sequential fashion
void SequentialMultiply(const polynomial& p1, const polynomial& p2, polynomial& res) {
	
  polynomial result;

	// Iterate through all the terms in the first polynomial 
	for (auto iter = p1.poly.begin(); iter != p1.poly.end(); iter++) {

		// Temporary polynomial for individual sums 
		polynomial temp;

		// Iterate through all the terms in the second polynomial
		for (auto other_iter = p2.poly.begin(); other_iter != p2.poly.end(); other_iter++) {
			temp.poly[(iter -> first) + (other_iter -> first)] = (iter -> second) * (other_iter -> second);
		}

		result = result + temp;
	}

	res = result;

}
*/

/* rajit's threads implementation
// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(const polynomial& other) const {

  polynomial result;                                    // Resulting polynomial after performing the multiplication operation
  std::vector<polynomial> threads_results(num_threads); // Vector containing the results from each thread
  std::vector<polynomial> threads_p1(num_threads);      // Vector containing the first polynomials in the multiplication of each thread
  std::vector<polynomial> threads_p2(num_threads);      // Vector containing the second polynomials in the multiplication of each thread
  std::vector<thread> threads;                          // Threads to perform sequential multiplication
  auto largest_poly_begin = (this -> poly).begin();     // Polynomial with the most number of terms
  auto largest_poly_end = (this -> poly).end();         // Polynomial with the most number of terms  


  // Find the polynomial with the largest terms
  int p1_size = (this -> poly).size(); // Number of terms in polynomial 1
  int p2_size = other.poly.size();     // Number of terms in polynomial 2
  if (p1_size >= p2_size) {
    largest_poly_begin = (this -> poly).begin();
    largest_poly_end = (this -> poly).end();
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

  // Divide the polynomial with the largest number of terms into 4 threads
  int thread_no = 0;
  while (largest_poly_begin != largest_poly_end) {

    // Insert a term into the current polynomial
    std::vector<std::pair<power, coeff>> p = {{largest_poly_begin -> first, largest_poly_begin -> second}};
    threads_p1[thread_no] = threads_p1[thread_no] + polynomial(p.begin(), p.end());
    largest_poly_begin++;
    thread_no++;
    if (thread_no >= num_threads) {
      thread_no = 0;
    }
  }

  // Perform sequential multiplication in 4 threads
  for (int i = 0; i < num_threads; i++) {
    threads.push_back(thread(SequentialMultiply, threads_p1[i], threads_p2[i], std::ref(threads_results[i])));
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
*/

// Multiplies two polynomials (polynomial * polynomial) and returns the result
  polynomial polynomial::operator*(const polynomial& other) const {
  polynomial p1 = *this;
  polynomial p2 = other;

  polynomial result;
  if (p1.poly.empty() == true || p2.poly.empty() == true) {
    return result;
  }

  int p1_size = p1.poly.size();
  int p2_size = p2.poly.size();
  if ((p1_size >= 30 && (p1_size / p2_size >= 3)) || ((p1_size * p2_size > 1000) && ((p2_size / p1_size >= 4) || (p1_size / p2_size > 0)))) { // use parallel
    // PARALLEL (threads = 4)
    int size = 4; // using only 4 threads
    int this_terms_per_thread = p1_size / size;
    vector<polynomial> temps(size, result); // initialize temps vector to all 0 polynomials

    // create vectors for powers and coeffs for `other`
    unordered_map<power, coeff> other_vals;
    for (auto p : p2.poly) {
      other_vals.insert({p.first, p.second});
    }

    // create vectors for powers and coeffs for `this` / 4
    auto this_iter = p1.poly.begin();
    auto this_end = p1.poly.end();
    // for 1st thread:
    unordered_map<power, coeff> this_vals1;
    int i = 0;
    while (i < this_terms_per_thread) {
      this_vals1.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 2nd thread:
    unordered_map<power, coeff> this_vals2;
    i = 0;
    while (i < this_terms_per_thread) {
      this_vals2.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 3rd thread:
    unordered_map<power, coeff> this_vals3;
    i = 0;
    while (i < this_terms_per_thread) {
      this_vals3.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 4th thread:
    unordered_map<power, coeff> this_vals4;
    while (this_iter != this_end) {
      this_vals4.insert({(*this_iter).first, (*this_iter).second});
      this_iter++;
    }

    // initialize threads vector AND call threads
    vector<thread> threads;
    i = 0;
    threads.push_back(thread(mult_p1_p2_4, this_vals1, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals2, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals3, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals4, other_vals, ref(temps.at(i))));
    threads.at(i);

    // wait for threads to finish
    for (int i = 0; i < size; i++) {
      threads.at(i).join();
    }

    // sum temps for result
    for (polynomial p : temps) {
      result = result + p;
    }

    return result;
  }

  // else use sequential:
  // SEQUENTIAL
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

// Finds the modulo of a polynomial and another polynomial (polynomial % polynomial) and returns the result
polynomial polynomial::operator%(const polynomial& other) const {

  // Create a copy of the current polynomial
  polynomial result = *this;
  polynomial divisor = other;
  size_t divisor_degree = divisor.find_degree_of();

  // Do the long division
  while (divisor_degree <= result.find_degree_of()) {

    // Find the degree of the current polynomial
    int result_degree = result.find_degree_of();

    // Get the mutliplication constant and degree
    int multiplication_constant = result.poly[result_degree] / divisor.poly[divisor_degree];
    int multiplication_power = result_degree - divisor_degree;

    // Construct the polynomial to multiply the divisior by
    std::vector<std::pair<power, coeff>> multiplication_polynomial_terms = {{multiplication_power, multiplication_constant}};
    polynomial multiplication_polynomial = polynomial(multiplication_polynomial_terms.begin(), multiplication_polynomial_terms.end());

    // Multiply the polynomial by the divisor and subtract from the result
    result = result + (-1 * (other * multiplication_polynomial));

  }

  return result;
}


/* TEST FUNCTIONS BELOW */

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

// Test function for parallel polynomial * polynomial
polynomial test_mult_p1_p2_parallel_4(polynomial p1, polynomial p2) {
  int p1_size = p1.poly.size();
  int p2_size = p2.poly.size();
  if ((p1_size >= 30 && (p1_size / p2_size >= 3)) || ((p1_size * p2_size > 1000) && ((p2_size / p1_size >= 4) || (p1_size / p2_size > 0)))) { // use parallel
    // cout << "USING PARALLEL" << endl;
    polynomial zero;
    if (p1.poly.empty() == true || p2.poly.empty() == true) {
      return zero;
    }

    // PARALLEL (threads = 4)
    int size = 4; // using only 4 threads
    int this_terms_per_thread = p1_size / size;
    vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

    // create vectors for powers and coeffs for `other`
    unordered_map<power, coeff> other_vals;
    for (auto p : p2.poly) {
      other_vals.insert({p.first, p.second});
    }

    // create vectors for powers and coeffs for `this` / 4
    auto this_iter = p1.poly.begin();
    auto this_end = p1.poly.end();
    // for 1st thread:
    unordered_map<power, coeff> this_vals1;
    int i = 0;
    while (i < this_terms_per_thread) {
      this_vals1.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 2nd thread:
    unordered_map<power, coeff> this_vals2;
    i = 0;
    while (i < this_terms_per_thread) {
      this_vals2.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 3rd thread:
    unordered_map<power, coeff> this_vals3;
    i = 0;
    while (i < this_terms_per_thread) {
      this_vals3.insert({(*this_iter).first, (*this_iter).second});
      i++;
      this_iter++;
    }
    // for 4th thread:
    unordered_map<power, coeff> this_vals4;
    while (this_iter != this_end) {
      this_vals4.insert({(*this_iter).first, (*this_iter).second});
      this_iter++;
    }

    // initialize threads vector AND call threads
    vector<thread> threads;
    i = 0;
    threads.push_back(thread(mult_p1_p2_4, this_vals1, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals2, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals3, other_vals, ref(temps.at(i))));
    threads.at(i);
    i++;
    threads.push_back(thread(mult_p1_p2_4, this_vals4, other_vals, ref(temps.at(i))));
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

  // else use sequential:
  // cout << "USING SEQUENTIAL" << endl;
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

// Test function for sequential polynomial * polynomial
polynomial test_mult_p1_p2_sequential(polynomial p1, polynomial p2) {
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

// Test function for parallel polynomial * int
polynomial test_mult_p_int_parallel_4(polynomial p, const int c) {
  polynomial zero;
  if (p.poly.empty() == true || c == 0) {
    return zero;
  }

  // PARALLEL (threads = 4)
  int size = 4; // using only 4 threads
  int this_terms_per_thread = p.poly.size() / size;
  vector<polynomial> temps(size, zero); // initialize temps vector to all 0 polynomials

  // create vectors for powers and coeffs for `this` / 4
  auto this_iter = p.poly.begin();
  auto this_end = p.poly.end();
  // for 1st thread:
  unordered_map<power, coeff> this_vals1;
  int i = 0;
  while (i < this_terms_per_thread) {
    this_vals1.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 2nd thread:
  unordered_map<power, coeff> this_vals2;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals2.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 3rd thread:
  unordered_map<power, coeff> this_vals3;
  i = 0;
  while (i < this_terms_per_thread) {
    this_vals3.insert({(*this_iter).first, (*this_iter).second});
    i++;
    this_iter++;
  }
  // for 4th thread:
  unordered_map<power, coeff> this_vals4;
  while (this_iter != this_end) {
    this_vals4.insert({(*this_iter).first, (*this_iter).second});
    this_iter++;
  }

  // initialize threads vector AND call threads
  vector<thread> threads;
  i = 0;
  threads.push_back(thread(mult_p_int_4, this_vals1, c, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(mult_p_int_4, this_vals2, c, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(mult_p_int_4, this_vals3, c, ref(temps.at(i))));
  threads.at(i);
  i++;
  threads.push_back(thread(mult_p_int_4, this_vals4, c, ref(temps.at(i))));
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

// Test function for sequential polynomial * int
polynomial test_mult_p_int_sequential(polynomial p, const int c) {
  polynomial zero;
  if (p.poly.empty() == true || c == 0) {
    return zero;
  }

  polynomial result;

  // Don't add zero terms
  if (c != 0) {
    for (auto iter = p.poly.begin(); iter != p.poly.end(); iter++) {
      result.poly.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * c));
    }
  }

  return result;
}
