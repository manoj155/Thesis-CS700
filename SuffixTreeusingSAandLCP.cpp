#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Suffix {
    int index;
    string suffix;
};

bool compareSuffix(const Suffix &a, const Suffix &b) {
    return a.suffix < b.suffix;
}

 vector<int> buildSuffixArray(const string &text) {
    int n = text.length();
    vector<Suffix> suffixes(n);

    for(int i = 0; i < n; ++i) {
        suffixes[i].index = i;
        suffixes[i].suffix = text.substr(i);
    }

    sort(suffixes.begin(), suffixes.end(), compareSuffix);

    vector<int> suffixArray(n);
    for (int i = 0; i < n; ++i) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

 vector<int> buildLCPArray(const  string &text, const  vector<int> &suffixArray) {
    int n = text.length();
    vector<int> lcp(n, 0);

    vector<int> invSuffixArray(n);
    for (int i = 0; i < n; ++i) {
        invSuffixArray[suffixArray[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (invSuffixArray[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = suffixArray[invSuffixArray[i] + 1];
        while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
            ++k;
        }

        lcp[invSuffixArray[i]] = k;

        if(k > 0) {
            --k;
        }
    }

    return lcp;
}

void buildSuffixTree(const  string &text) {
    vector<int> suffixArray = buildSuffixArray(text);
    vector<int> lcpArray = buildLCPArray(text, suffixArray);

    // Now you can use the suffix array and LCP array to build the suffix tree.
    // This part is more complex and usually involves constructing the tree using nodes.

    // For simplicity, I'm omitting the suffix tree construction part here.
}

int main() {
    string text = "banana";
    buildSuffixTree(text);
    return 0;
}
