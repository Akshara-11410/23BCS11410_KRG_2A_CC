#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        Node* links[26];
        bool flag = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a'])
                node->links[ch - 'a'] = new Node();
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a'])
                return false;
            node = node->links[ch - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->links[ch - 'a'])
                return false;
            node = node->links[ch - 'a'];
        }
        return true;
    }
};
