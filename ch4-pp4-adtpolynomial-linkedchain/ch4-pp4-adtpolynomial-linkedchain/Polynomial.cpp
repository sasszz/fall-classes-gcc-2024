//
//  Polynomial.cpp
//  ch4-pp4-adtpolynomial-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include "polynomial.h"
#include <iomanip>

// Constructor
Polynomial::Polynomial() {
    p = NULL;
}

// Add a term to the polynomial
void Polynomial::polynomial_add(float c, int e) {
    PolynomialNode* temp = p;
    if (temp == NULL) {
        temp = new PolynomialNode;
        p = temp;
    } else {
        while (temp->next != NULL) temp = temp->next;
        temp->next = new PolynomialNode;
        temp = temp->next;
    }
    temp->coefficient = c;
    temp->exponent = e;
    temp->next = NULL;
}

// Find the coefficient of a term with a given power
float Polynomial::coefficient(int power) {
    PolynomialNode* temp = p;
    while (temp != NULL) {
        if (temp->exponent == power) {
            return temp->coefficient;
        }
        temp = temp->next;
    }
    return 0.0;
}

// Change the coefficient of a term with a specific power
void Polynomial::changeCoefficient(float newCoefficient, int power) {
    PolynomialNode* temp = p;
    while (temp != NULL) {
        if (temp->exponent == power) {
            temp->coefficient = newCoefficient;
            return;
        }
        temp = temp->next;
    }
}

// Find the degree of the polynomial
int Polynomial::degree() {
    PolynomialNode* temp = p;
    int degree = -1;
    while (temp != NULL) {
        if (temp->exponent > degree) degree = temp->exponent;
        temp = temp->next;
    }
    return degree;
}

// Display the polynomial
void Polynomial::display_polynomial() {
    PolynomialNode* temp = p;
    
    // Use fixed width for coefficients and exponents for alignment
    cout << left << setw(5) << "Coef" << " " << setw(5) << "Exp" << endl;
    cout << "-------------------" << endl;
    
    while (temp != nullptr) {
        // Display coefficients and exponents with alignment
        cout << left << setw(5) << temp->coefficient << " ^" << setw(5) << temp->exponent << endl;
        temp = temp->next;
    }
}

// Display the polynomial in linear form
void Polynomial::display_polynomial_flat() {
    PolynomialNode* temp = p;
    bool firstTerm = true;

    while (temp != NULL) {
        if (!firstTerm) {
            if (temp->coefficient > 0) cout << " + "; // Display "+" if not the first term
        }

        if (temp->exponent != 0) {
            cout << temp->coefficient << "x^" << temp->exponent;
        } else {
            cout << temp->coefficient;
        }

        temp = temp->next;
        firstTerm = false;
    }
    cout << endl;
}

// Add two polynomials and store the result in the current polynomial
void Polynomial::polynomial_add(Polynomial& p1, Polynomial& p2) {
    PolynomialNode *temp1 = p1.p, *temp2 = p2.p;
    PolynomialNode* z = nullptr;

    while (temp1 != NULL || temp2 != NULL) {
        if (p == NULL) {
            p = new PolynomialNode;
            z = p;
        } else {
            z->next = new PolynomialNode;
            z = z->next;
        }
        if (temp1 == NULL) {
            z->coefficient = temp2->coefficient;
            z->exponent = temp2->exponent;
            temp2 = temp2->next;
        } else if (temp2 == NULL) {
            z->coefficient = temp1->coefficient;
            z->exponent = temp1->exponent;
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            z->coefficient = temp2->coefficient;
            z->exponent = temp2->exponent;
            temp2 = temp2->next;
        } else if (temp1->exponent > temp2->exponent) {
            z->coefficient = temp1->coefficient;
            z->exponent = temp1->exponent;
            temp1 = temp1->next;
        } else {
            z->coefficient = temp1->coefficient + temp2->coefficient;
            z->exponent = temp1->exponent;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    z->next = NULL;
}

// Destructor
Polynomial::~Polynomial() {
    PolynomialNode* q;
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
}
