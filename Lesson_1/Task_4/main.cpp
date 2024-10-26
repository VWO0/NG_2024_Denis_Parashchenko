#include <iostream>
using namespace std;

int money;

void checkLowSalary(int money) {
    if (1000 - money > 0) {
        cout << "Work harder!" << endl;
    }
}

void checkMediumSalary(int money) {
    if (money / 1000 > 1 && money / 1000000 == 0) {
        cout << "You're doing a good job!" << endl;
    }
}

void checkHighSalary(int money) {
    if (money / 1000000 > 0) {
        cout << "Yes, you are a millionaire!" << endl;
    }
}

void CheckFunctions(int money) {
    checkLowSalary(money);
    checkMediumSalary(money);
    checkHighSalary(money);
}

int main() {
    cout << "How much do you earn?" << endl;
    cin >> money;

    CheckFunctions(money);

    cout << "But you're great!" << endl;
    return 0;
}
