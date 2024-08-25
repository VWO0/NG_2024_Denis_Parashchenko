#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int countWords(const string& str) {
    string cleanedStr;
    for (char c : str) {
        if (!isdigit(c) && !ispunct(c) && !isspace(c)) {
            cleanedStr += c;
        } else if (isspace(c)) {
            cleanedStr += ' ';
        }
    }

    istringstream stream(cleanedStr);
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
    cout << "Number of words: " << wordCount << endl;

    return 0;
}
