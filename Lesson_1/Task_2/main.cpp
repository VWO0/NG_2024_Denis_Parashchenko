#include <iostream>

using namespace std;

int main() {
    float data_1,data_2;
    char operations;
    cout << "Enter number_1." <<endl;
    cin >> data_1;
    cout << "Select operations." <<endl;
    cin >> operations;
    cout << "Enter number_2." <<endl;
    cin >> data_2;
    if (operations == '+'){
        cout << "Result: " << data_1 + data_2 << endl;
    }/*else if (operations == 'Operation name') {

    }
*/
    return 0;
}
