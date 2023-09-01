#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
  int n = s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    cout << "Initial value of J: " << j << " and i: " << i << endl;

    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
      cout << "Chance of Value of J: " << j << " and i: " << i << endl;
    }

    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

int main() {
  string pattern = "ababd";
  vector<int> prefixFuncAns = prefix_function(pattern);
  for (auto it : prefixFuncAns) {
    cout << it << " ";
  }
  string text = "ababcabcabababd";
  int pos = -1;
  int i = 0, j= 0;
  while(i<text.size()) {
    if(text[i]==pattern[j]) {
      j++;
      i++;
    }
    else if(j!=0) {
      j = prefixFuncAns[j-1];
    }
    else {
      i++;
    }
    if(j==pattern.size()) {
      pos = i - pattern.size();
      break;
    }
  }
  cout << endl << "1st repeating position: " << pos << endl;
}
