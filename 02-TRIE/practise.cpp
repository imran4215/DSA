#include<bits/stdc++.h>
using namespace std;

struct Node{
    bool EoW;
    Node* children[26];

    Node(){
        EoW=false;
        for(int i=0 ; i<26 ; i++){
            children[i]=NULL;
        }
    }
};

class TRIE{
    Node* root;

    int realPos(char ch){
        return ch-'a';
    }

    char realChar(int pos){
        return pos+'a';
    }

    void printTRIE_(Node* cur,string s=""){
        if(cur->EoW==true){
            cout<<s<<endl;
        }
        for(int i=0 ; i<26 ; i++){
            if(cur->children[i]==NULL) continue;
            char ch=realChar(i);
            printTRIE_(cur->children[i],s+ch);
        }
    }

    public:
    TRIE(){
        root=new Node();
    }

    void insert(string s){
        Node* cur=root;

        for(int i=0 ; i<(int)s.size() ; i++){
            int j=realPos(s[i]);

            if(cur->children[j]==NULL){
                cur->children[j]=new Node();
            }
            cur=cur->children[j];
        }
        cur->EoW=true;
    }

    bool search(string s){
        Node* cur=root;

        for(int i=0 ; i<(int)s.size() ; i++){
            int j=realPos(s[i]);
            if(cur->children[j]==NULL) return false;
            cur=cur->children[j];
        }
        return true;
    }

    void printTRIE(){
        printTRIE_(root,"");
    }
};


int main()
{
    TRIE trie;
    trie.insert("app");
    trie.insert("apple");
    trie.insert("applet");
    trie.insert("cat");
    trie.insert("dogandcat");
    trie.insert("catanddog");
    trie.printTRIE();
    
    return 0;
}