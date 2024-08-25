#include <iostream>
#include <limits>

using namespace std;

const int numAccounts = 10;

void calculateMinMax(float bank[], int size, float &minBalance, float &maxBalance, int &minIndex, int &maxIndex) {
    minBalance = numeric_limits<float>::max();
    maxBalance = numeric_limits<float>::min();
    minIndex = -1;
    maxIndex = -1;

    for (int index = 0; index < size; index++) {
        if (bank[index] < minBalance) {
            minBalance = bank[index];
            minIndex = index;
        }
        if (bank[index] > maxBalance) {
            maxBalance = bank[index];
            maxIndex = index;
        }
    }
}

float calculateTotal(float bank[], int size) {
    float total = 0;
    for (int index = 0; index < size; index++) {
        total += bank[index];
    }
    return total;
}

int main() {
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

        cout << "Do you want to deposit (d), withdraw (w), or check balance (c)? ";
        cin >> action;

        if (action == 'd' || action == 'w') {
            cout << "Enter amount: ";
            cin >> amount;

            if (amount < 0) {
                cout << "Amount cannot be negative!" << endl;
                continue;
            }

            if (action == 'd') {
                bank[accountNumber - 1] += amount;
            } else if (action == 'w') {
                if (amount > bank[accountNumber - 1]) {
                    cout << "Not enough funds in the account!" << endl;
                } else {
                    bank[accountNumber - 1] -= amount;
                }
            }
        } else if (action == 'c') {
            cout << "Balance of account " << accountNumber << ": " << bank[accountNumber - 1] << endl;
        } else {
            cout << "Unknown action!" << endl;
        }
    }

    float minBalance, maxBalance;
    int minIndex, maxIndex;
    calculateMinMax(bank, numAccounts, minBalance, maxBalance, minIndex, maxIndex);
    float total = calculateTotal(bank, numAccounts);

    cout << "Total amount on all accounts: " << total << endl;
    cout << "Minimum balance: " << minBalance << " (Account " << minIndex + 1 << ")" << endl;
    cout << "Maximum balance: " << maxBalance << " (Account " << maxIndex + 1 << ")" << endl;

    return 0;
}
