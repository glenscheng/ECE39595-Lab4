#include <map>
#include "poly.h"

using std::map;


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

// Canonical form 
std::vector<std::pair<power, coeff>> polynomial::canonical_form() const {return std::vector<std::pair<power, coeff>>();}

// Returns the degree of the polynomial
size_t polynomial::find_degree_of() {
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

    std::cout << "0" << std::endl;
}

// Adds two polynomials (polynomial + polynomial) and returns the result
polynomial polynomial::operator+(polynomial& other) {

    polynomial result;

    // Check which polynomial has the higer degree
    if ((this -> find_degree_of()) >= other.find_degree_of()) {

        // Iterate through all the terms in both of the polynomials
        for (size_t curr_power = this -> find_degree_of(); curr_power >= 0; curr_power--) {

            // Check if the polynomials contain the power
            // If power is there, then add up the coefficients.
            // Otherwise, keep one of the polynomials' coefficient
            if ((this -> poly).find(curr_power) != (this -> poly).end()) {

                if (other.poly.find(curr_power) != other.poly.end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
                } else {
                    result.poly[curr_power] = (this -> poly)[curr_power];
                }
                
            } else {
                
                // If both of the polynomials' coefficients are 0, then don't 
                // insert any term to keep the non-zero policy consistent
                if (other.poly.find(curr_power) != other.poly.end()) {
                    result.poly[curr_power] = other.poly[curr_power];
                }
            }

        }

    } else {
        
        // Iterate through all the terms in both of the polynomials
        for (size_t curr_power = other.find_degree_of(); curr_power >= 0; curr_power--) {

            // Check if the polynomials contain the power
            // If power is there, then add up the coefficients.
            // Otherwise, keep one of the polynomials' coefficient
            if (other.poly.find(curr_power) != other.poly.end()) {

                if ((this -> poly).find(curr_power) != (this -> poly).end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
                } else {
                    result.poly[curr_power] = other.poly[curr_power];
                }
                
            } else {
                
                // If both of the polynomials' coefficients are 0, then don't 
                // insert any term to keep the non-zero policy consistent
                if ((this -> poly).find(curr_power) != (this -> poly).end()) {
                    result.poly[curr_power] = (this -> poly)[curr_power];
                }
            }

        }

    }
    
    return result;
}

// Adds a polynomial and a number (polynomial + int) and returns the result
polynomial polynomial::operator+(const int i) {
    
    // Create a copy of the current polynomial
    polynomial result = *this; 

    // Don't add zero terms
    if (i != 0) {
        // Add the constant to the polynomial
        if (result.poly.find(0) != result.poly.end()) {
            result.poly[0] = result.poly[0] + i;
        } else {
            result.poly[0] = i;
        }
    }


    return result;
}

// Adds a number and a polynomial (int + polynomial) and returns the result
polynomial operator+(const int i, polynomial& polynomial_object) {
    
    // Create a copy of the current polynomial
    polynomial result = polynomial_object; 

    // Don't add zero terms
    if (i != 0) {
        // Add the constant to the polynomial
        if (result.poly.find(0) != result.poly.end()) {
            result.poly[0] = result.poly[0] + i;
        } else {
            result.poly[0] = i;
        }
    }

    return result;
}

// Multiplies a polynomial and a number (polynomial * int) and returns the result
polynomial polynomial::operator*(const int i) {

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
polynomial operator*(const int i, polynomial& polynomial_object) { 
    
    polynomial result;

    // Don't add zero terms
    if (i != 0) {
        for (auto iter = polynomial_object.poly.begin(); iter != polynomial_object.poly.end(); iter++) {
            result.poly.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
        }
    }

    return result;
}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial polynomial::operator*(polynomial& other) {

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
