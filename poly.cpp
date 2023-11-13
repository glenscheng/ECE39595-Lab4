#include <map>
#include "poly.h"

// Construct a new polynomial object that is the number 0 (ie. 0x^0)
polynomial::polynomial() {}

// Construct a new polynomial object from an iterator to pairs of <power,coeff>
template <typename Iter>
polynomial::polynomial(Iter begin, Iter end) {
    
    Iter p = begin; // Points to the current pair

    for (Iter p = begin; p != end; p++) {

        // Insert the current power and coefficient pair
        (this -> poly).insert(*p);

    }

}

// Returns the degree of the polynomial
size_t polynomial::find_degree_of() {
    if (!((this -> poly).empty())) {
        return (this -> poly).rbegin() -> first; 
    } else {
        return 0;
    }
}

// Prints the polynomial
void print() const {

    for (auto p = (this -> poly).rbegin(); p != (this -> poly).rend(); p++) {
        int pow = p -> first;
        int cof = p -> second;
        std::cout << "(" << cof << "x^" << pow << ") + ";  
    }

    std::cout << "0" << std::endl;
}

// Adds two polynomials (polynomial + polynomial) and returns the result
polynomial polynomial::operator+(const polynomial& other) const {

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
                    result.poly[curr_power] = other.poly.[curr_power];
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
polynomial polynomial::operator+(const int i) const {
    
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
polynomial operator+(const int i, const polynomial& polynomial_object) {
    
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
polynomial polynomial::operator*(const int i) const {

    polynomial result;

    // Don't add zero terms
    if (i != 0) {
        for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); iter++) {
            result.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
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
            result.insert(std::pair<power, coeff>(iter -> first, (iter -> second) * i));
        }
    }

    return result;
}

// Multiplies two polynomials (polynomial * polynomial) and returns the result
polynomial operator*(const polynomial& other) const {

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