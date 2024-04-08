#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    bool isEnd;
    TrieNode*children[26];

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++) children[i]=NULL;
        isEnd=false;
    }
};
class Trie {
private:
    void insertTries(TrieNode*root,string word,int i){
        if(i==word.size()){
            root->isEnd=true;
            return;
        }

        int idx=(word[i]-'a');

        if(root->children[idx]==nullptr){
            root->children[idx]=new TrieNode(word[i]);
        }
        root=root->children[idx];
        insertTries(root,word,i+1);
    }
    bool SearchTrie(TrieNode*root,string word,int i){
        if(i==word.size()){
            return root->isEnd;
        }
        int idx=word[i]-'a';
        
        if(root->children[idx]!=NULL){
            root=root->children[idx];
        }
        else{
            return false;
        }
        return SearchTrie(root,word,i+1);
    }
    bool startWithTrie(TrieNode*root,string word,int i){
        if(i==word.size()){
            return true;
        }
        int idx=word[i]-'a';
        
        if(root->children[idx]!=NULL){
            root=root->children[idx];
        }
        else{
            return false;
        }
        return startWithTrie(root,word,i+1);
    }
public:
    TrieNode*root=new TrieNode('\0');
    Trie() {
        TrieNode*root=new TrieNode('\0');
    }
    
    void insert(string word) {
        insertTries(root,word,0);
    }
    
    bool search(string word) {
        return SearchTrie(root,word,0);
    }
    
    bool startsWith(string prefix) {
        return startWithTrie(root,prefix,0);
    }
};
