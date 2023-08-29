#include <iostream>
#include <string>

using namespace std;
// Brute-force pattern matching algorithm
vector<int> bruteForcePatternSearch(const string& text, const string& pattern) {
    vector<int> occurrences;

    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) // If pattern is found at index i
            occurrences.push_back(i);
    }

    return occurrences;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    vector<int> occurrences = bruteForcePatternSearch(text, pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found in the text.\n";
    } else {
        cout << "Pattern found at positions:";
        for (int pos : occurrences) {
            cout << " " << pos;
        }
        cout << "\n";
    }

    return 0;
}
