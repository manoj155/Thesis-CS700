#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Brute-force pattern matching algorithm
vector<vector<int>> bruteForceMultiPatternSearch(const string& text, const vector<string>& patterns) {
    vector<vector<int>> occurrences(patterns.size());

    int n = text.length();
    for (size_t p = 0; p < patterns.size(); ++p) {
        int m = patterns[p].length();
        for (int i = 0; i <= n - m; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (text[i + j] != patterns[p][j])
                    break;
            }

            if (j == m) // If pattern is found at index i
                occurrences[p].push_back(i);
        }
    }

    return occurrences;
}

int main() {
    string text;
    int numPatterns;

    cout << "Enter the text: ";
    std::cin >> text;

    cout << "Enter the number of patterns: ";
    cin >> numPatterns;

    vector<string> patterns(numPatterns);
    for (int i = 0; i < numPatterns; ++i) {
        cout << "Enter pattern " << i + 1 << ": ";
        cin >> patterns[i];
    }

    vector<vector<int>> occurrences = bruteForceMultiPatternSearch(text, patterns);

    for (size_t p = 0; p < patterns.size(); ++p) {
        if (occurrences[p].empty()) {
            cout << "Pattern " << patterns[p] << " not found in the text.\n";
        } else {
            cout << "Pattern " << patterns[p] << " found at positions:";
            for (int pos : occurrences[p]) {
                cout << " " << pos;
            }
            cout << "\n";
        }
    }

    return 0;
}
