#ifndef POLY_H
#define POLY_H

#include <vector>
#include <utility>
#include <cstddef>
#include <map>
#include <iostream>

using power = size_t;
using coeff = int;
using std::map;

class polynomial
{
  private:
    map<power, coeff> poly;

  public:
    /**
     * @brief Construct a new polynomial object that is the number 0 (ie. 0x^0)
     *
     */
    polynomial();

    /**
     * @brief Construct a new polynomial object from an iterator to pairs of <power,coeff>
     *
     * @param Iter
     *  An iterator that points to a std::pair<power, coeff>
     * @param begin
     *  The start of the container to copy elements from
     * @param end
     *  The end of the container to copy elements from
     */
    template <typename Iter> polynomial(Iter begin, Iter end);

    /**
     * @brief Construct a new polynomial object from an existing polynomial object
     *
     * @param other
     *  The polynomial to copy
     */
    polynomial(const polynomial &other);

    /**
     * @brief Return map
     *
     * @return
     *  The map
     */
    map<power, coeff> get_poly() const { return poly; }

    /**
     * @brief Clear map
     *
     */
    void clear_poly() { poly.clear(); }


    /**
     * @brief Insert key value pair into map
     *
     * @param p
     *  Key of insertion
     * @param c
     *  Value of insertion
     */
    void insert_poly(power p, coeff c) { poly.insert({p,c}); }

    /**
     * @brief Prints the polynomial.
     *
     * Only used for debugging, isn't graded.
     *
     */
    void print() const;

    /**
     * @brief Turn the current polynomial instance into a deep copy of another
     * polynomial
     *
     * @param other
     * The polynomial to copy
     * @return
     * A reference to the copied polynomial
     */
    polynomial &operator=(const polynomial &other);


    /**
     * Overload the +, * and % operators. The function prototypes are not
     * provided.
     * 
     * Addition (+) should support
     * 1. polynomial + polynomial
     * 2. polynomial + int
     * 3. int + polynomial
     * 
     * Multiplication (*) should support
     * 1. polynomial * polynomial
     * 2. polynomial * int
     * 3. int * polynomial
     * 
     * Modulo (%) should support
     * 1. polynomial % polynomial
     */
    /**
     * @brief Adds two polynomials (polynomial + polynomial) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    polynomial operator+(const polynomial& other) const;  

    /**
     * @brief Adds a polynomial and a number (polynomial + int) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    polynomial operator+(const int i) const; 

    /**
     * @brief Adds a number and a polynomial (int + polynomial) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    friend polynomial operator+(const int i, const polynomial& polynomial_object);

    /**
     * @brief Multiplies two polynomials (polynomial * polynomial) and returns the result
     *i
     * @return polynomial
     *  The result of the addition
     */
    polynomial operator*(const polynomial& other) const;  

    /**
     * @brief Multiplies a polynomial and a number (polynomial * int) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    polynomial operator*(const int i) const; 

    /**
     * @brief Multiplies a number and a polynomial (int * polynomial) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    friend polynomial operator*(const int i, const polynomial& polynomial_object);
    
    /**
     * @brief Finds the modulo of a polynomial and another polynomial (polynomial * int) and returns the result
     *
     * @return polynomial
     *  The result of the addition
     */
    polynomial operator%(const polynomial& other) const; 

    /**
     * @brief Returns the degree of the polynomial
     *
     * @return size_t
     *  The degree of the polynomial
     */
    size_t find_degree_of() const;

    /**
     * @brief Returns a vector that contains the polynomial is canonical form. This
     *        means that the power at index 0 is the largest power in the polynomial,
     *        the power at index 1 is the second largest power, etc.
     *
     *        ie. x^2 + 7x^4 + 1 would be returned as [(4,7),(2,1),(0,1)]
     *
     *        Note: any terms that have a coefficient of zero aren't returned in
     *        in the canonical form, with one exception.
     *        See the above example (there's no x^3 term, so
     *        there's no entry in the vector for x^3)
     *
     *        The only exception to this is the polynomial 0. If your polynomial is
     *        just the constant 0 then you would return a single entry of [(0,0)]
     *
     *        ie. y = 0 would be returned as [(0,0)]
     *
     * @return std::vector<std::pair<power, coeff>>
     *  A vector of pairs representing the canonical form of the polynomial
     */
    std::vector<std::pair<power, coeff>> canonical_form() const;

    /**
     * @brief Returns whether the polynomial contains a coeff at a specific power
     *
     * @param pwr
     *  The specific power
     * @param exp_c
     *  The expected coeff
     * @return bool
     *  Whether the coeffs match
     */
    bool check_coeff(power pwr, coeff exp_c);
};

// Construct a new polynomial object from an iterator to pairs of <power,coeff>
template <typename Iter> polynomial::polynomial(Iter begin, Iter end) {
  while (begin != end) {
    // Ignore 0 coefficients
    if ((*begin).second == 0) {
      begin++;
      continue;
    }
    // Insert the current power and coefficient pair
    poly.insert(*begin);
    
    begin++;
  }
}

#endif
