#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool EoW;
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

    void collectWords(Node* cur, string s, vector<string>& result) {
        if (cur->EoW) {
            result.push_back(s);
        }
        for (int i = 0; i < 26; i++) {
            if (cur->children[i] != NULL) {
                char ch = realChar(i);
                collectWords(cur->children[i], s + ch, result);
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

    bool search(string s) {
        Node* cur = root;
        for (int i = 0; i < (int)s.size(); i++) {
            int j = relPos(s[i]);
            if (cur->children[j] == NULL) return false;
            cur = cur->children[j];
        }
        return cur->EoW;
    }

    vector<string> wordsAsPrefix(string s) {
        vector<string> result;
        Node* cur = root;

        string prefix = "";
        for (char c : s) {
            prefix += c;
            int j = relPos(c);

            if (cur->children[j] == NULL) {
                break;
            }
            cur = cur->children[j];

            if (cur->EoW) {
                result.push_back(prefix);
            }
        }
        return result;
    }

    void printTRIE() {
        vector<string> result;
        collectWords(root, "", result);
        for (const string& word : result) {
            cout << word << endl;
        }
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

    trie.printTRIE();

    string testWord = "apple";
    vector<string> prefixes = trie.wordsAsPrefix(testWord);

    cout << "Prefixes for '" << testWord << "':" << endl;
    for (const string& prefix : prefixes) {
        cout << prefix << endl;
    }

    return 0;
}
