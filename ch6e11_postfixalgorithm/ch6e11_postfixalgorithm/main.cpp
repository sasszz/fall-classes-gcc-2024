//
//  main.cpp
//  ch6e11_postfixalgorithm
//
//  Created by Lucie Chevreuil on 9/22/24.
//

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Function to evaluate a postfix expression and print the trace
int evaluatePostfixExpression(const string& postfixExpression, const map<char, int>& variableValues) {
    stack<int> evaluationStack;
    stringstream expressionStream(postfixExpression);
    char token;

    cout << "Evaluating expression: " << postfixExpression << endl;

    // Read each token from the postfix expression
    while (expressionStream >> token) {
        // If the token is a variable (a, b, c, etc.), push its value onto the stack
        if (isalpha(token)) {
            int value = variableValues.at(token);
            evaluationStack.push(value);
            cout << "Pushed " << token << " (" << value << ") onto the stack. Stack: ";
        }
        // If the token is an operator, apply the operation to the top two elements
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = evaluationStack.top();
            evaluationStack.pop();
            int operand1 = evaluationStack.top();
            evaluationStack.pop();
            int result;

            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    cout << "Applied " << operand1 << " + " << operand2 << " = " << result << ". Stack: ";
                    break;
                case '-':
                    result = operand1 - operand2;
                    cout << "Applied " << operand1 << " - " << operand2 << " = " << result << ". Stack: ";
                    break;
                case '*':
                    result = operand1 * operand2;
                    cout << "Applied " << operand1 << " * " << operand2 << " = " << result << ". Stack: ";
                    break;
                case '/':
                    result = operand1 / operand2; // Assuming no division by zero
                    cout << "Applied " << operand1 << " / " << operand2 << " = " << result << ". Stack: ";
                    break;
            }
            evaluationStack.push(result);
        }

        // Print the current status of the stack
        stack<int> tempStack = evaluationStack;
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }

    // The final result will be the last value remaining on the stack
    int finalResult = evaluationStack.top();
    cout << "Final result: " << finalResult << endl;
    return finalResult;
}

int main() {
    // Map for variable values (a = 7, b = 3, c = 12, d = -5, e = 1)
    map<char, int> variableValues = {
        {'a', 7},
        {'b', 3},
        {'c', 12},
        {'d', -5},
        {'e', 1}
    };

    // Test cases for postfix expressions
    string expression1 = "a b c + -";   // a = 7, b = 3, c = 12, result should be -8
    string expression2 = "a b c - d * +"; // a = 7, b = 3, c = 12, d = -5, result should be 52
    string expression3 = "a b + c - d e * +"; // a = 7, b = 3, c = 12, d = -5, e = 1, result should be -7

    // Evaluating the expressions with trace
    cout << "-------------------------------------" << endl;
    evaluatePostfixExpression(expression1, variableValues);
    cout << "-------------------------------------" << endl;
    evaluatePostfixExpression(expression2, variableValues);
    cout << "-------------------------------------" << endl;
    evaluatePostfixExpression(expression3, variableValues);
    cout << "-------------------------------------" << endl;

    return 0;
}
