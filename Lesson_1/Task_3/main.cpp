#include <iostream>
using namespace std;

int money, million_check = 1000001;

void checkLowSalary(int money) {
    if (1000 - money > 0) {
        cout << "Work harder!" << endl;
    }
}

void checkHighSalary(int money) {
    if (money - 1000000 > 0) {
        cout << "Yes, you are a millionaire!" << endl;
    }
    if (1000000 - money >= 0 && money - 1000 >= 0) {
        cout << "You're doing a good job!" << endl;
    }
}

int main() {
    cout << "How much do you earn?" << endl;
    cin >> money;

    checkLowSalary(money);
    checkHighSalary(money);

    cout << "But you’re great!" << endl;
    return 0;
}
