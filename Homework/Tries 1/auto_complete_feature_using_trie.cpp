#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    set<string>allStrings;
    TrieNode*children[26];

    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

class Trie{
    private:
    void insertTries(TrieNode*root,string word){
        int n=word.size();
        for(auto ch:word){
            if(root->children[ch-'a']!=NULL){
                root->children[ch-'a']->allStrings.insert(word);
            }
            else{
                TrieNode*child= new TrieNode();
                root->children[ch-'a']=child;
                child->allStrings.insert(word);
            }
            root=root->children[ch-'a'];
        }
    }
    set<string> querySolver(TrieNode*root,string word){
        int n=word.size();
        for(auto ch:word){
            if(root->children[ch-'a']==NULL) return{};
            root=root->children[ch-'a'];
        }
        return root->allStrings;
    }

    public:
    TrieNode*root=new TrieNode();

    void insertIntoTrie(vector<string>nums){
        for(int i=0;i<nums.size();i++){
            insertTries(root,nums[i]);
        }
    }
    vector<string> query(string word){
        set<string>ans=querySolver(root,word);
        vector<string>arr;
        for(auto str:ans){
            arr.push_back(str);
        }
        return arr;
    }

};

int main(){
    Trie*t=new Trie();
    vector<string>nums={"aman","ayush","ayushi","ayushman","abhinav","sunil","john cena"};
    t->insertIntoTrie(nums);
    vector<string>ans;
    ans=t->query("john");
    if(ans.size()==0) cout<<"no word with this keyword prefix found";
    else{
        for(auto i:ans)  cout<<i<<" ";
    }
}