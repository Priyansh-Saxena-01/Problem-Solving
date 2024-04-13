#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isEnd;
    int count;
    TrieNode*children[26];

    TrieNode(){
        for(int i=0;i<26;i++) children[i]=NULL;
        isEnd=false;
        count=0;
    }
};

class Trie{
    private:
    //unordered_map<string,int>helper;
    void insertTries(TrieNode*root,string word){
        int n=word.size();
        for(int i=0;i<n;i++){
            int idx=(word[i]-'a');

            if(root->children[idx]==NULL){
                root->children[idx]=new TrieNode();
            }
            root->children[idx]->count+=1;
            root=root->children[idx];
        }
        root->isEnd=true;
    }
    int querySolver(TrieNode*root,string word){
        int n=word.size();
        int maxCount=0;
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            maxCount+=root->children[idx]->count;
            root=root->children[idx];
        }
        return maxCount;
    }

    public:
    TrieNode*root=new TrieNode();

    void insertIntoTrie(vector<string>nums){
        for(int i=0;i<nums.size();i++){
            insertTries(root,nums[i]);
        }
    }
    vector<int> query(vector<string>words){
        int n=words.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(querySolver(root,words[i]));
        }
        return ans;
    }

};

int main(){
    Trie*t=new Trie();
    vector<string>nums={"abc","ab","bc","b"};
    t->insertIntoTrie(nums);
    vector<int>ans;
    ans=t->query(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }

}