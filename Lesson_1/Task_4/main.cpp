#include <iostream>
#include <cmath> // Для функции sqrt

using namespace std;

int main() {
    float result, data_1, data_2;
    char operations;

    cout << "Enter number_1." << endl;
    cin >> data_1;

    cout << "Select operations: +,-,*,/,s (square), r (square root)" << endl;
    cin >> operations;

    if (operations != 's' && operations != 'r') {
        cout << "Enter number_2." << endl;
        cin >> data_2;
    }

    switch (operations) {
    case '+': {
        result = data_1 + data_2;
        break;
    }
    case '-': {
        result = data_1 - data_2;
        break;
    }
    case '*': {
        result = data_1 * data_2;
        break;
    }
    case '/': {
        if (data_2 != 0) {
            result = data_1 / data_2;
        } else {
            cout << "Error: Division by zero." << endl;
            return 1;
        }
        break;
    }
    case 's': { // Квадрат числа
        result = data_1 * data_1;
        break;
    }
    case 'r': { // Квадратный корень числа
        if (data_1 >= 0) {
            result = sqrt(data_1);
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
