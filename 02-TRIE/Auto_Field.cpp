#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool EoW; // End of Word
    Node* children[26];

    Node() {
        EoW = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class TRIE {
    Node* root;

    int relPos(char ch) {
        return ch - 'a';
    }

    char realChar(int pos) {
        return pos + 'a';
    }

    void collectWords(Node* cur, string prefix, vector<string>& result) {
        if (cur->EoW==true) {
            result.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (cur->children[i] != NULL) {
                char ch = realChar(i);
                collectWords(cur->children[i], prefix + ch, result);
            }
        }
    }

public:
    TRIE() {
        root = new Node();
    }

    void insert(string s) {
        Node* cur = root;
        for (int i = 0; i < (int)s.size(); i++) {
            int j = relPos(s[i]);
            if (cur->children[j] == NULL) {
                cur->children[j] = new Node();
            }
            cur = cur->children[j];
        }
        cur->EoW = true;
    }

    vector<string> autoComplete(string prefix) {
        Node* cur = root;
        for (int i = 0; i < (int)prefix.size(); i++) {
            int j = relPos(prefix[i]);
            if (cur->children[j] == NULL) {
                return {}; // No words with the given prefix
            }
            cur = cur->children[j];
        }

        vector<string> result;
        collectWords(cur, prefix, result);
        return result;
    }
};

int main() {
    TRIE trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("applet");
    trie.insert("cat");
    trie.insert("dogandcat");
    trie.insert("catanddog");
    

    string prefix = "ap";
    vector<string> suggestions = trie.autoComplete(prefix);

    cout << "Auto-completions for prefix '" << prefix << "':" << endl;
    for (const string& word : suggestions) {
        cout << word << endl;
    }

    return 0;
}
