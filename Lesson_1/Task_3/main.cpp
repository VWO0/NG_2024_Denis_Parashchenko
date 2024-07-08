#include <iostream>

using namespace std;
int money,million_check = 1000000;
void checkLowSalary(int money);
void checkHighSalary(int money);

void checklowsalary(int money) {
    if (money < 1000){
        cout << "Work harder!" << endl;
    }
}

void checkhighsalary(int money) {
    if (million_check < money) {
        cout << "Yes, you are a millionaire!" << endl;
    }
    if (million_check > money) {
        cout << "You're doing a good job!" << endl;
    }
}

int main()
{

    cout << "How much do you earn?" <<endl;
    cin >> money;
    checklowsalary(money);

    return 0;
}
