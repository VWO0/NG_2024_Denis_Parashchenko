#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int countWords(const string& str) {
    istringstream stream(str);
    string word;
    int count = 0;
    while (stream >> word) {
        count++;
    }
    return count;
}

int main() {
    string input;
    cout << "Enter string: ";
    getline(cin, input);

    int wordCount = countWords(input);
    cout << "Number of words per line: " << wordCount << endl;

    return 0;
}
