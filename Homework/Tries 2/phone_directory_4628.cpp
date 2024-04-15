#include<bits/stdc++.h>
using namespace std;   

class TrieNode{
    public:
    set<string>names;
    TrieNode*children[26];
    
    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};
class Trie{
    private:
    void TrieInsert(TrieNode*curr,string str){
        TrieNode*root=curr;
        for(auto ch:str){
            if(root->children[ch-'a']==NULL){
                TrieNode*child=new TrieNode();
                root->children[ch-'a']=child;
            }
            root->children[ch-'a']->names.insert(str);
            root=root->children[ch-'a'];
        }
    }
    public:
    TrieNode*root=new TrieNode();
    
    void insertIntoTries(vector<string>nums){
        for(auto it:nums){
            TrieInsert(root,it);
        }
    }
    bool flag=true;
    vector<vector<string>>querySolver(string str){
        TrieNode*curr=root;
        vector<vector<string>>ans;
        for(auto ch:str){
            vector<string>temp;
            set<string>st;
            if(flag && curr->children[ch-'a']!=NULL){
                st=curr->children[ch-'a']->names;
                curr=curr->children[ch-'a'];
                for(auto i:st){
                    temp.push_back(i);
                }
            }
            else{
                flag =false;
                temp.push_back("0");
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
    
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie*t=new Trie();
        vector<string>temp;
        for(int i=0;i<n;i++){
            temp.push_back(contact[i]);
        }
        t->insertIntoTries(temp);
    
        return t->querySolver(s);
        
    }
};