#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int countWords(const string& str) {
    string cleanedStr = str;
    cleanedStr.erase(remove_if(cleanedStr.begin(), cleanedStr.end(), [](unsigned char c) {
                         return ispunct(c);
                     }), cleanedStr.end());

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
    cout << "Number of words per line: " << wordCount << endl;

    return 0;
}
