#include <map>
#include "poly.h"

// Adds two polynomials (polynomial + polynomial) and returns the result
polynomial polynomial::operator+(const polynomial& other) const {

    polynomial result;

    // Check which polynomial has the higer degree
    if ((this -> find_degree_of()) >= other.find_degree_of()) {

        // Iterate through all the terms in the polynomial
        for (auto iter = (this -> poly).begin(); iter != (this -> poly).end(); i++) {

            // Check if the second polynomial contains the power
            size_t curr_power = (*iter).first; 
            if (other.contains(curr_power)) {
                result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
            } else {
                result.poly[curr_power] = (this -> poly)[curr_power];
            }

            iter++;
        }

    } else {
        
        // Iterate through all the terms in the polynomial
        for (auto iter = other.poly.begin(); iter != other.poly.end(); i++) {

            // Check if the second polynomial contains the power
            size_t curr_power = (*iter).first; 
            if ((this -> poly).contains(curr_power)) {
                result.poly[curr_power] = (this -> poly)[curr_power] + other.poly[curr_power];
            } else {
                result.poly[curr_power] = other.poly[curr_power];
            }


        } 

    }
    
    return result;
}

// Adds a polynomial and a number (polynomial + int) and returns the result
polynomial polynomial::operator+(const int i) const {
    
    // Create a copy of the current polynomial
    polynomial result = *this; 

    // Add the constant to the polynomial
    if (result.poly.contains(0)) {
        result.poly[0] = result.poly[0] + i;
    } else {
        result.poly[0] = i;
    }

    return result;
}

// Adds a number and a polynomial (int + polynomial) and returns the result
polynomial operator+(const int i, const polynomial& polynomial_object) {
    
    // Create a copy of the current polynomial
    polynomial result = polynomial_object; 

    // Add the constant to the polynomial
    if (result.poly.contains(0)) {
        result.poly[0] = result.poly[0] + i;
    } else {
        result.poly[0] = i;
    }

    return result;
}