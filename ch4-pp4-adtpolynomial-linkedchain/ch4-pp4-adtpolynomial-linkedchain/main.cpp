//
//  main.cpp
//  ch4-pp4-adtpolynomial-linkedchain
//
//  Created by Lucie Chevreuil on 9/15/24.
//

#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {
    // Define polynomials
    Polynomial p1, p2;

    // Coefficients and exponents for p1
    // 14x^5 + 15x^4 + 17x^2 + 18x^1 + 19
    int coeffs1[] = {14, 15, 17, 18, 19};
    int exps1[] = {5, 4, 2, 1, 0};
    
    // Coefficients and exponents for p2
    // 15x^6 + 25x^5 + 35x^4 + 45x^3 + 65x^1
    int coeffs2[] = {15, 25, 35, 45, 65};
    int exps2[] = {6, 5, 4, 3, 1};

    // Add terms to p1 using a for loop
    for (int i = 0; i < 5; ++i) {
        p1.polynomial_add(coeffs1[i], exps1[i]);
    }

    // Add terms to p2 using a for loop
    for (int i = 0; i < 5; ++i) {
        p2.polynomial_add(coeffs2[i], exps2[i]);
    }

    // Display polynomials
    cout << endl;
    cout << "First polynomial: ";
    cout << endl;
    p1.display_polynomial();
    
    cout << endl;
    cout << "Second polynomial: ";
    cout << endl;
    p2.display_polynomial();

    // Add the two polynomials and display result
    Polynomial p3;
    p3.polynomial_add(p1, p2);
    
    cout << endl;
    cout << "Resulting polynomial: ";
    cout << endl;
    p3.display_polynomial();
    
    cout << endl;
    p1.display_polynomial_flat();
    p2.display_polynomial_flat();
    p3.display_polynomial_flat();

    return 0;
}
