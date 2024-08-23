#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int number;

    cout << "Enter numbers (0 to complete):";
    while (numbers.size() < 20) {
        cin >> number;
        if (number == 0) break;
        numbers.push_back(number);
    }


    int maxStars = 0;
    for (int n : numbers) {
        if (n > maxStars) maxStars = n;
    }


    cout << "Result:" << endl;
    for (int n : numbers) {
        int spaces = (maxStars - n) / 2;
        cout << string(spaces, ' ') << string(n, '*') << endl;
    }

    return 0;
}
