#include <iostream>
#include <vector>
#include "poly.h"
#include "test_addition.h"

int test_addition_constant_1_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {std::pair<size_t, int>(0, 1)};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + 1;

    // Assert
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition() {
    test_addition_constant_1_post();
    return EXIT_SUCCESS;
}