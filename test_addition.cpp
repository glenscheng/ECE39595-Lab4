#include <iostream>
#include <vector>
#include <pair>
#include "poly.h"

int test_addition_constant_1_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}, {1, 1}, {2, 1}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + 1;

    // Assert
}

int test_addition() {
    return EXIT_SUCCESS;
}