//
//  Polynomial.hpp
//  ch4-pp4-adtpolynomial-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include <iostream>
using namespace std;

class Polynomial {
private:
    // Node structure to represent each term in the polynomial
    struct PolynomialNode {
        float coefficient;
        int exponent;
        PolynomialNode* next; // Pointer to the next node
    } *p; // Pointer to the head of the linked list

public:
    // Constructor
    Polynomial();

    // Add a term to the polynomial
    void polynomial_add(float c, int e);

    // Find the coefficient of a term with a specific exponent
    float coefficient(int power);

    // Find the degree of the polynomial
    int degree();

    // Display the polynomial
    void display_polynomial();
    
    // Display the polynomial in linear form
    void display_polynomial_flat();

    // Add two polynomials and store the result in the current polynomial
    void polynomial_add(Polynomial& p1, Polynomial& p2);

    // Change the coefficient of a specific term
    void changeCoefficient(float newCoefficient, int power);

    // Destructor to clear all nodes
    ~Polynomial();
};
