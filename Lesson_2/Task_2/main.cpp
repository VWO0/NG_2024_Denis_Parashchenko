#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int inputNumber;

    cout << "Enter numbers (0 to complete): ";
    while (numbers.size() < 20) {
        cin >> inputNumber;
        if (inputNumber == 0) break;
        numbers.push_back(inputNumber);
    }

    int maxNumber = 0;
    for (int currentNumber : numbers) {
        if (currentNumber > maxNumber) {
            maxNumber = currentNumber;
        }
    }

    cout << "Result:" << endl;
    for (int currentNumber : numbers) {
        int leadingSpaces = (maxNumber - currentNumber) / 2;
        cout << string(leadingSpaces, ' ') << string(currentNumber, '*') << endl;
    }

    return 0;
}
