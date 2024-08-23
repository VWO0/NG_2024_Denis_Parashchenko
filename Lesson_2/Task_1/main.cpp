#include <iostream>
#include <limits>

using namespace std;

int main() {
    const int numAccounts = 10;
    float bank[numAccounts] = {0};
    int accountNumber;
    float amount;
    char action;

    while (true) {
        cout << "Enter account number (1-10) or 0 to exit: ";
        cin >> accountNumber;

        if (accountNumber == 0) {
            break;
        }

        if (accountNumber < 1 || accountNumber > numAccounts) {
            cout << "Invalid account number!" << endl;
            continue;
        }

        cout << "Do you want to deposit (p) or withdraw (s) money? ";
        cin >> action;

        cout << "Enter amount: ";
        cin >> amount;

        if (action == 'p') {
            bank[accountNumber - 1] += amount;
        } else if (action == 's') {
            if (amount > bank[accountNumber - 1]) {
                cout << "There are not enough funds in the account!" << endl;
            } else {
                bank[accountNumber - 1] -= amount;
            }
        } else {
            cout << "Unknown action!" << endl;
        }
    }

    // Calculate total, minimum, and maximum balances
    float total = 0;
    float minBalance = numeric_limits<float>::max();
    float maxBalance = numeric_limits<float>::min();

    for (int i = 0; i < numAccounts; i++) {
        total += bank[i];
        if (bank[i] < minBalance) minBalance = bank[i];
        if (bank[i] > maxBalance) maxBalance = bank[i];
    }

    cout << "Amount on all accounts: " << total << endl;
    cout << "Minimum balance: " << minBalance << endl;
    cout << "Maximum balance: " << maxBalance << endl;

    return 0;
}
