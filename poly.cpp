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
polynomial polynomial::operator+(const int i) {
    
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
polynomial operator+(const int i, polynomial& polynomial_object) {
    
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

// Finds the remainder of a polynomial divided by another polynomial
polynomial polynomial::operator%(polynomial& other) {
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
