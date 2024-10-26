#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float result, num_1, num_2;
    char operations;

    cout << "Enter number_1." << endl;
    cin >> num_1;

    cout << "Select operations: +,-,*,/,s (square), r (square root)" << endl;
    cin >> operations;

    if (operations != 's' && operations != 'r') {
        cout << "Enter number_2." << endl;
        cin >> num_2;
    }

    switch (operations) {
    case '+': {
        result = num_1 + num_2;
        break;
    }
    case '-': {
        result = num_1 - num_2;
        break;
    }
    case '*': {
        result = num_1 * num_2;
        break;
    }
    case '/': {
        if (num_2 != 0) {
            result = num_1 / num_2;
        } else {
            cout << "Error: Division by zero." << endl;
            return 1;
        }
        break;
    }
    case 's': {
        result = num_1 * num_1;
        break;
    }
    case 'r': {
        if (num_1 >= 0) {
            result = sqrt(num_1);
        } else {
            cout << "Error: Cannot calculate square root of a negative number." << endl;
            return 1;
        }
        break;
    }
    default: {
        cout << "Error: Invalid operation." << endl;
        return 1;
    }
    }

    cout << "Result: " << result << endl;

    return 0;
}
