#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the Christmas tree: ";
    cin >> height;

    for (int i = 1; i <= height; ++i) {
        for (int j = 0; j < height - i; ++j) {
            cout << ' ';
        }
        for (int k = 0; k < (2 * i - 1); ++k) {
            cout << '*';
        }
        cout << endl;
    }

    for (int i = 0; i < height - 1; ++i) {
        cout << ' ';
    }
    cout << '*' << endl;

    return 0;
}
