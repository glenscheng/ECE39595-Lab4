#include <map>
#include "poly.h"

// Construct a new polynomial object that is the number 0 (ie. 0x^0)
polynomial::polynomial() {}

// Copy constructor 
polynomial::polynomial(const polynomial &other) {}

// Assignment operator 
polynomial& polynomial::operator=(const polynomial &other) {return *this;}

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
	auto p = (this -> poly).begin();
	auto q = other.poly.end();
	auto p_end = (this -> poly).end();
	auto q_end = other.poly.end();

	// Iterate through both of the polynomials and add up the terms
	while (p != p_end || q != q_end) {

		// Check if reached the end of one of the polynomials
		if (p == p_end) {
			result.poly.insert(std::pair<power, coeff>(q -> first, q -> second));
			q++;
		} else if (q == q_end) {
			result.poly.insert(std::pair<power, coeff>(p -> first, p -> second));
			p++;
		} else if (p -> first == q -> first) {
			result.poly.insert(std::pair<power, coeff>(p -> first, (p -> second) + (q -> second)));
			p++;
			q++;
		} else if (p -> first > q -> first) {
			result.poly.insert(std::pair<power, coeff>(p -> first, p -> second));
			p++;
		} else {
			result.poly.insert(std::pair<power, coeff>(q -> first, q -> second));
			q++;
		}

	}
	
	// Return the result
	/**
    // Check which polynomial has the higer degree
    if ((this -> find_degree_of()) >= other.find_degree_of()) {

        // Iterate through all the terms in both of the polynomials
        for (int curr_power = this -> find_degree_of(); curr_power >= 0; curr_power--) {

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
        for (int curr_power = other.find_degree_of(); curr_power >= 0; curr_power--) {

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

    }**/
    
    return result;
}

// Adds a polynomial and a number (polynomial + int) and returns the result
polynomial polynomial::operator+(const int i) {
    
    // Create a copy of the current polynomial
    polynomial result = *this; 

    // Don't add zero terms
    if (i != 0) {

        size_t pow = 0;

        // Add the constant to the polynomial
        if (result.poly.find(pow) != result.poly.end()) {
            result.poly[pow] = result.poly[pow] + i;
        } else {
            result.poly[pow] = i;
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

        size_t pow = 0;

        // Add the constant to the polynomial
        if (result.poly.find(pow) != result.poly.end()) {
            result.poly[pow] = result.poly[pow] + i;
        } else {
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
