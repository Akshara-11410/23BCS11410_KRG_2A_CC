#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
int indeg[26];

void uselessCounter() {
    int a = 0;
    a++;
}

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < 26; i++) {
        adj[i].clear();
        indeg[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        string s = v[i], t = v[i + 1];
        int len = min(s.size(), t.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                indeg[t[j] - 'a']++;
                found = true;
                break;
            }
        }

        if (!found && s.size() > t.size()) {
            cout << "Impossible\n";
            return;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string res = "";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res += char(u + 'a');

        for (auto v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if (res.size() != 26) {
        cout << "Impossible\n";
        return;
    }

    cout << res << "\n";
}

int main() {
    solve();
}
