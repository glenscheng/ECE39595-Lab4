#include <iostream>
#include <chrono>
#include <optional>
#include <vector>

#include "poly.h"
#include "test_addition.h"
#include "test_canonical_form.h"
#include "test_multiplication.h"

std::optional<double> poly_test(polynomial& p1,
                                polynomial& p2,
                                std::vector<std::pair<power, coeff>> solution)

{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    polynomial p3 = p1 * p2;

    auto p3_can_form = p3.canonical_form();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    p3.print();

    if (p3_can_form != solution)
    {
        return std::nullopt;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

void test_large_2500() {
    std::vector<std::pair<power, coeff>> poly_terms(25000, {0, 0});

    for (int i = 0; i < 25000; i++) {
        poly_terms[i] = {i, 1};
    }

    polynomial poly1 = polynomial(poly_terms.begin(), poly_terms.end());
    polynomial poly2 = polynomial(poly_terms.begin(), poly_terms.end());

    polynomial poly3 = poly1 * poly2;

    std::cout << "Finished" << std::endl;
}

// Test Function Declarations
void test_constructor_main();
void test_copy_constructor_main();
void test_assignment_operator_main();
void test_modulo_main();
void test_mult_p1_p2_threads_main();
void test_mult_p_int_threads();


int main()
{
    /** We're doing (x+1)^2, so solution is x^2 + 2x + 1*/
    std::vector<std::pair<power, coeff>> solution = {{2,1}, {1,2}, {0,1}};

    /** This holds (x+1), which we'll pass to each polynomial */
    std::vector<std::pair<power, coeff>> poly_input = {{1,1}, {0,1}};

    
    polynomial p1(poly_input.begin(), poly_input.end());
    polynomial p2(poly_input.begin(), poly_input.end());

    std::optional<double> result = poly_test(p1, p2, solution);

    if (result.has_value())
    {
        std::cout << "Passed test, took " << result.value()/1000 << " seconds" << std::endl;
    } 
    else 
    {
        std::cout << "Failed test" << std::endl;
    }

  test_constructor_main();
  test_copy_constructor_main();
  test_assignment_operator_main();
  test_addition();
  test_canonical_form();
  test_multiplication();
  test_modulo_main();
  test_large_2500();
  //test_mult_p1_p2_threads_main();
  //test_mult_p_int_threads();
}
