#include <iostream>
using namespace std;

int main() {
    int height;
    cout << "Enter the height of the Christmas tree: ";
    cin >> height;

    for (int row = 1; row <= height; ++row) {
        for (int space = 0; space < height - row; ++space) {
            cout << ' ';
        }
        for (int star = 0; star < (2 * row - 1); ++star) {
            cout << '*';
        }
        cout << endl;
    }

    for (int space = 0; space < height - 1; ++space) {
        cout << ' ';
    }
    cout << '*' << endl;

    return 0;
}
