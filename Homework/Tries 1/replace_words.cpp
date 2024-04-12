#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isEnd;
    TrieNode*children[26];

    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
        isEnd=false;
    }
};

class Trie{
    private:
    void insertTries(TrieNode*root,string word){
        int n=word.size();
        for(int i=0;i<n;i++){
            int idx=(word[i]-'a');

            if(root->children[idx]==NULL){
                root->children[idx]=new TrieNode();
            }
            root=root->children[idx];
        }
        root->isEnd=true;

    }
    string querySolver(TrieNode*root,string word){
        int n=word.size();
        string ans="";
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(root->isEnd){
                return ans;
            }
            if(root->children[idx]==NULL){
                if(root->isEnd){
                    return word.substr(0,i);
                }
                else return "";
            }
            ans+=word[i];
            root=root->children[idx];
        }
        return ans;
    }

    public:
    TrieNode*root=new TrieNode();

    void insertIntoTrie(vector<string>nums){
        for(int i=0;i<nums.size();i++){
            insertTries(root,nums[i]);
        }
    }
    string query(string word){
        string temp=querySolver(root,word);
        if(temp.size()==0) return word;
        return temp;

    }

};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie*t=new Trie();
        t->insertIntoTrie(dictionary);

        stringstream word(sentence);
        string ans="",temp;
        for(;word>>temp;){
            ans+=t->query(temp);
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};