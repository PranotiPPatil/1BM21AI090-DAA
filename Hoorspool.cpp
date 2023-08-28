#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 256;

void generateBadCharTable(const string& pattern, vector<int>& badChar) {
    int patternLength = pattern.length();

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        badChar[i] = patternLength;
    }

    for (int i = 0; i < patternLength - 1; ++i) {
        badChar[pattern[i]] = patternLength - 1 - i;
    }
}

int hoorespoolSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength > textLength) {
        return -1;
    }

    vector<int> badChar(ALPHABET_SIZE);
    generateBadCharTable(pattern, badChar);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;
        } else {
            shift += badChar[text[shift + patternLength - 1]];
        }
    }

    return -1;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    int matchIndex = hoorespoolSearch(text, pattern);
    if (matchIndex != -1) {
        cout << "Pattern found at index " << matchIndex << " in the text." << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
