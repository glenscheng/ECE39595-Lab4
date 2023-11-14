#include <iostream>
#include <vector>
#include "poly.h"
#include "test_multiplication.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

void t_product_0th_order_positive_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly * 8;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, 72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_0th_order_negative_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly * -8;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, -72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_positive_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly * 8;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 40}, {4, 32}, {3, 24}, {2, 16}, {1, 8}, {0, 72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_negative_constant_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly * -8;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, -40}, {4, -32}, {3, -24}, {2, -16}, {1, -8},{0, -72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_1st_order_zero_post() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with zero" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 0" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly * 0;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_0th_order_positive_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = 8 * poly;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, 72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_0th_order_negative_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = -8 * poly;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{0, -72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_positive_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = 8 * poly;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, 40}, {4, 32}, {3, 24}, {2, 16}, {1, 8}, {0, 72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_negative_constant_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 0th order polynomial with a numeric constant" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = -8" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = -8 * poly;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{5, -40}, {4, -32}, {3, -24}, {2, -16}, {1, -8},{0, -72}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_1st_order_zero_pre() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with zero" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms = {{1, 1}, {0, 9}};
	polynomial poly = polynomial(poly_terms.begin(), poly_terms.end());
	std::cout << "poly = ";
	poly.print();
	std::cout << "const = 0" << std::endl;

	// Act
	// Multiply a constant to the polynomial
	polynomial product = 0 * poly;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_1st_order_1st_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 1st order polynomial with a 1st order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{1, 5}, {0, 9}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{1, 3}, {0, 5}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{2, 15}, {1, 52}, {0, 45}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_1st_order_1st_order_commutative() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 1st order polynomial with a 1st order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{1, 3}, {0, 5}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{1, 5}, {0, 9}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{2, 15}, {1, 52}, {0, 45}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_5th_order() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 6}, {4, 5}, {3, 4}, {2, 3}, {1, 2}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{10, 30}, {9, 49}, {8, 58}, {7, 58}, {6, 50}, {5, 134}, {4, 101}, {3, 73}, {2, 49}, {1, 28}, {0, 90}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_5th_order_commutative() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 6}, {4, 5}, {3, 4}, {2, 3}, {1, 2}, {0, 10}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{10, 30}, {9, 49}, {8, 58}, {7, 58}, {6, 50}, {5, 134}, {4, 101}, {3, 73}, {2, 49}, {1, 28}, {0, 90}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_5th_order_missing_terms_commutative() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 6}, {4, 5}, {2, 3}, {1, 2}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{10, 30}, {9, 49}, {8, 38}, {7, 42}, {6, 38}, {5, 76}, {4, 57}, {3, 7}, {2, 29}, {1, 18}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_5th_order_missing_terms() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 6}, {4, 5}, {2, 3}, {1, 2}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {{10, 30}, {9, 49}, {8, 38}, {7, 42}, {6, 38}, {5, 76}, {4, 57}, {3, 7}, {2, 29}, {1, 18}};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

void t_product_5th_order_zero() {

	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Printing multiplication of 5th order polynomial with a 5th order polynomial" << std::endl;

	// Arrange 
	// Create a polynomial
	std::vector<std::pair<power, coeff>> poly_terms1 = {{5, 5}, {4, 4}, {3, 3}, {2, 2}, {1, 1}, {0, 9}};
	std::vector<std::pair<power, coeff>> poly_terms2 = {{5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}};
	polynomial poly1 = polynomial(poly_terms1.begin(), poly_terms1.end());
	polynomial poly2 = polynomial(poly_terms2.begin(), poly_terms2.end());
	std::cout << "poly1 = ";
	poly1.print();
	std::cout << "poly2 = ";
	poly2.print();

	// Act
	// Multiply a constant to the polynomial
	polynomial product = poly1 * poly2;
	std::cout << "product = ";
	product.print();

	// Assert
	// Check whether the polynomial has correct terms
	bool test_passed = true;
	std::vector<std::pair<power, coeff>> poly_terms_expected = {};
	for (auto Iter = poly_terms_expected.begin(); Iter != poly_terms_expected.end(); Iter++) {
		if (!product.check_coeff(Iter -> first, Iter -> second)) {
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

int test_multiplication() {
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	t_product_0th_order_positive_constant_post();
	t_product_0th_order_negative_constant_post();
	t_product_5th_order_positive_constant_post();
	t_product_5th_order_negative_constant_post();
	t_product_1st_order_zero_post();
	t_product_0th_order_positive_constant_pre();
	t_product_0th_order_negative_constant_pre();
	t_product_5th_order_positive_constant_pre();
	t_product_5th_order_negative_constant_pre();
	t_product_1st_order_zero_post();
	t_product_1st_order_1st_order();
	t_product_1st_order_1st_order_commutative();
	t_product_5th_order_5th_order();
	t_product_5th_order_5th_order_commutative();
	t_product_5th_order_5th_order_missing_terms();
	t_product_5th_order_5th_order_missing_terms_commutative();
	t_product_5th_order_zero();
	std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	return EXIT_SUCCESS;
}
