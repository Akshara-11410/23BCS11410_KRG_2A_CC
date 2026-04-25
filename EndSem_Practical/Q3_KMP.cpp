#include <bits/stdc++.h>
using namespace std;


vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0; 
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


vector<int> KMPsearch(string text, string pattern) {
    vector<int> result;
    vector<int> lps = computeLPS(pattern);

    int i = 0; 
    int j = 0; 

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            result.push_back(i - j); 
            j = lps[j - 1]; 
        } else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}


int main() {
    string text, pattern;
    
    cout << "Enter text: ";
    cin >> text;
    
    cout << "Enter pattern: ";
    cin >> pattern;

    vector<int> indices = KMPsearch(text, pattern);

    if (indices.empty()) {
        cout << "Pattern not found\n";
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : indices) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}
