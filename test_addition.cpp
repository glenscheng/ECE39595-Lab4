#include <iostream>
#include <vector>
#include "poly.h"
#include "test_addition.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

void t_0th_order_positive_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + 1;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_positive_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + 1;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_positive_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = 1 + poly;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_positive_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + 1;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_negative_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -9" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + -9;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_negative_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -9" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + -9;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_negative_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -9" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = -9 + poly;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_negative_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -9" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = -9 + poly;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_0_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 0}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 0" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + 0;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_0_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 0}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 0" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = 0 + poly;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_missing_term_positive_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly + 1;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 1}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_missing_term_positive_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 2}, {4, 5}, {3, 2}, {1, 10}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 1" << std::endl;

	// Act
	// Add a constant to the polynomial
	polynomial sum = 1 + poly;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {1, 10}, {0, 1}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_5th_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 5}, {4, 7}, {3, 1}, {2, 2}, {1, 8}, {0, 5}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 7}, {4, 12}, {3, 3}, {2, 4}, {1, 18}, {0, 15}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_3rd_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a 3rd order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::vector<std::pair<power, coeff>> poly_terms2 = {{3, 1}, {2, 2}, {1, 8}, {0, 5}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 3}, {2, 4}, {1, 18}, {0, 15}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_3rd_order_5th_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 3rd order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::vector<std::pair<power, coeff>> poly_terms1 = {{3, 1}, {2, 2}, {1, 8}, {0, 5}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 3}, {2, 4}, {1, 18}, {0, 15}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_5th_order_negative_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 5}, {4, 7}, {3, -2}, {2, 2}, {1, 8}, {0, -10}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 7}, {4, 12}, {2, 4}, {1, 18}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_5th_order_missing_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 5}, {4, 7}, {2, 2}, {1, 8}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 7}, {4, 12}, {3, 2}, {2, 4}, {1, 18}, {0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_2nd_order_missing_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 5th order polynomial with a 3rd order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::vector<std::pair<power, coeff>> poly_terms2 = {{2, 2}, {1, 8}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 2}, {2, 4}, {1, 18}, {0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_3rd_order_5th_order_missing_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing addition of 3rd order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 2}, {4, 5}, {3, 2}, {2, 2}, {1, 10}, {0, 10}};
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::vector<std::pair<power, coeff>> poly_terms1 = {{3, 1}, {2, 2}, {1, 8}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	std::cout << "poly 1 = ";
	poly1.print();
	std::cout << "poly 2 = ";
	poly2.print();

	// Act
	// Add a constant to the polynomial
	polynomial sum = poly1+poly2;
	std::cout << "sum = ";
	sum.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 2}, {4, 5}, {3, 3}, {2, 4}, {1, 18}, {0, 10}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!sum.check_coeff(Iter -> first, Iter -> second)) {
			std::cout << "Expected: " << Iter -> second << "x^" << Iter -> first << std::endl;
			std::cout << "Actual:   " << Iter -> second << "x^" << Iter -> first << std::endl;
			test_passed = false;
		}
	}

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

int test_addition() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	t_0th_order_positive_constant_post();
	t_5th_order_positive_constant_post();
	t_0th_order_positive_constant_pre();
	t_5th_order_positive_constant_pre();
	t_0th_order_negative_constant_post();
	t_5th_order_negative_constant_post();
	t_0th_order_negative_constant_pre();
	t_5th_order_negative_constant_pre();
	t_0th_order_0_constant_post();
	t_0th_order_0_constant_pre();
	t_5th_order_missing_term_positive_constant_post();
	t_5th_order_missing_term_positive_constant_pre();
	t_5th_order_5th_order();
	t_5th_order_3rd_order();
	t_3rd_order_5th_order();
	t_5th_order_5th_order_negative_terms();
	t_5th_order_5th_order_missing_terms();
	t_5th_order_2nd_order_missing_terms();
	t_3rd_order_5th_order_missing_terms();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    return EXIT_SUCCESS;
}
