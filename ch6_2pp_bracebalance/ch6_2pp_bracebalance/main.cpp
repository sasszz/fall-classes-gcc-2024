//
//  main.cpp
//  ch6_2pp_bracebalance
//
//  Created by Lucie Chevreuil on 9/28/24.
//

#include <iostream>
#include "BraceBalance.h"

using namespace std;

int main() {
    string test1 = "{ab(c[d])e}";
    string test2 = "{ab(c))";

    cout << "\n--- Test 1 ---" << endl;
    bool result = BraceBalance(test1);
    if (result)
        cout << "The string \"" << test1 << "\" is brace balanced." << endl;
    else
        cout << "The string \"" << test1 << "\" is not brace balanced." << endl;

    cout << "\n--- Test 2 ---" << endl;
    result = BraceBalance(test2);
    if (result)
        cout << "The string \"" << test2 << "\" is brace balanced." << endl;
    else
        cout << "The string \"" << test2 << "\" is not brace balanced." << endl;

    return 0;
}
