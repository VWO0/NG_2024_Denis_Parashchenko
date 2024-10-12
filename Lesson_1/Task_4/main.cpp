#include <iostream>
using namespace std;

int money;

void checkLowSalary(int money) {
    if (1000 - money > 0) {
        cout << "Work harder!" << endl;
    }
}

void checkHighSalary(int money) {
    if (money >= 1000000) {
        cout << "Yes, you are a millionaire!" << endl;
    } else if (money >= 1000) {
        cout << "You're doing a good job!" << endl;
    }
}

int main() {
    cout << "How much do you earn?" << endl;
    cin >> money;

    checkLowSalary(money);
    checkHighSalary(money);

    cout << "But youre great!" << endl;
    return 0;
}
