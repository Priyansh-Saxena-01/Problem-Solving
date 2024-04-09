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

class Trie{
    private:
    void insertTries(TrieNode*root,string word,int i){
        if(i>=word.size()){
            root->isEnd=true;
            return;
        }

        int idx=(word[i]-'a');

        if(root->children[idx]==NULL){
            root->children[idx]=new TrieNode(word[i]);
        }
        root=root->children[idx];
        insertTries(root,word,i+1);
    }
    bool SearchTrie(TrieNode*root,string word,int i){
        if(i>=word.size()){
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

    public:
    TrieNode*root=new TrieNode('\0');

    void insertIntoTrie(string word){
        insertTries(root,word,0);
    }
    bool searchInTrie(string word){
        return SearchTrie(root,word,0);
    }

};

int main(){
    Trie*t=new Trie();

    string word="abcd";
    t->insertIntoTrie(word);

    if(t->searchInTrie("abcd")){
        cout<<"word found";
    }
    else{
        cout<<"word not found";
    }
}