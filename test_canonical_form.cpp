#include <iostream>
#include <vector>
#include "poly.h"
#include "test_canonical_form.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

void t_5th_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 10}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 10}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_5th_order_random() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{2, 2}, {4, 4}, {5, 5}, {3, 3}, {1, 1}, {0, 10}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 10}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_3rd_order_missing_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 3rd order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{3, 3}, {2, 2}, {1, 1}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{3, 3}, {2, 2}, {1, 1}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_3rd_order_random_missing() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 3rd order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 10}, {3, 3}, {1, 1}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{3, 3}, {1, 1}, {0, 10}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_3rd_order_zero_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 3rd order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{3, 3}, {2, 2}, {1, 1}, {0, 0}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{3, 3}, {2, 2}, {1, 1}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_zero_polynomial() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 0th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 0}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{0, 0}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

void t_0th_order_polynomial() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing canonical form of a 0th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 10}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();

	// Act
	// Get the canonical form of the polynomial
	auto canonical_form = poly.canonical_form();

	// Assert
	// Check whether the polynomial has correct terms
	std::vector<std::pair<power, coeff>> expected_canonical_form = {{0, 10}};
	bool test_passed = canonical_form == expected_canonical_form;

	if (test_passed) {
		std::cout << GRN << "Passed!\n" << RESET;
	} else {
		std::cout << RED << "Failed!\n" << RESET;
	}

	std::cout << "------------------------------------------" << std::endl;
}

int test_canonical_form() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	t_5th_order();
	t_5th_order_random();
	t_3rd_order_missing_terms();
	t_3rd_order_random_missing();
	t_3rd_order_zero_terms();
	t_zero_polynomial();
	t_0th_order_polynomial();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	return EXIT_SUCCESS;
}
