#include <iostream>
#include <vector>
#include "poly.h"
#include "test_addition.h"

int test_addition_constant_1_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + 1;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_constant_99_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {std::pair<size_t, int>(0, 1)};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + -99;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_constant_1_pre() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {std::pair<size_t, int>(0, 1)};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = 1 + poly;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_constant_99_pre() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {std::pair<size_t, int>(0, 1)};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = -99 + poly;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_higher_order_constant_1_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}, {1, 3}, {2, 6}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + 1;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_higher_order_constant_99_post() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}, {1, 3}, {2, 6}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = poly + -99;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_higher_order_constant_1_pre() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}, {1, 3}, {2, 6}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = 1 + poly;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_higher_order_constant_99_pre() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms = {{0, 1}, {1, 3}, {2, 6}};
    polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());

    // Act
    polynomial sum = -99 + poly;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_poly_1st_order_0th_order() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms1 = {{0, 1}, {1, 3}};
    std::vector<std::pair<size_t, int>> poly_terms2 = {{0, 7}};
    polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
    polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());

    // Act
    polynomial sum = poly1 + poly2;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_poly_1st_order_1st_order() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms1 = {{0, 1}, {1, 3}};
    std::vector<std::pair<size_t, int>> poly_terms2 = {{0, 9}, {1, 5}};
    polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
    polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());

    // Act
    polynomial sum = poly1 + poly2;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_poly_1st_order_1st_order_2() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms1 = {{0, 1}, {1, 3}};
    std::vector<std::pair<size_t, int>> poly_terms2 = {{0, 9}, {1, -5}};
    polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
    polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());

    // Act
    polynomial sum = poly1 + poly2;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

int test_addition_poly_3rd_order_1st_order() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms1 = {{0, 1}, {1, 3}, {2, 5}, {3, 4}};
    std::vector<std::pair<size_t, int>> poly_terms2 = {{0, 9}, {1, 5}};
    polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
    polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());

    // Act
    polynomial sum = poly1 + poly2;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}

/*int test_addition_poly_3rd_order_1st_order() {
    
    // Arrange
    // Create a polynomial
    std::vector<std::pair<size_t, int>> poly_terms1 = {{0, 1}, {1, 3}, {2, 5}, {3, 4}};
    std::vector<std::pair<size_t, int>> poly_terms2 = {{0, 9}, {1, 5}};
    polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
    polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());

    // Act
    polynomial sum = poly1 + poly2;

    // Assert
    std::cout << "sum = ";
    sum.print();

    return EXIT_SUCCESS;
}*/

int test_addition() {

    test_addition_constant_1_post();
    test_addition_constant_99_post();
    test_addition_constant_1_pre();
    test_addition_constant_99_pre();
    test_addition_higher_order_constant_1_post();
    test_addition_higher_order_constant_99_post();
    test_addition_higher_order_constant_1_pre();
    test_addition_higher_order_constant_99_pre();
    test_addition_poly_1st_order_0th_order();
    test_addition_poly_1st_order_1st_order();
    test_addition_poly_1st_order_1st_order_2();
    test_addition_poly_3rd_order_1st_order();

    return EXIT_SUCCESS;
}
