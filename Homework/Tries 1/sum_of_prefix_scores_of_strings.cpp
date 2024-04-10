#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    int slen;
    int sidx;
    TrieNode*children[26];

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};

class Trie{
    private:
    void insertTries(TrieNode*root,string word,int index){

        int n=word.size();
        for(int k=n-1;k>=0;--k){

            int idx=(word[k]-'a');

            if(root->children[idx]!=NULL){

                if(root->children[idx]->slen==n){
                    root->children[idx]->sidx=min(root->children[idx]->sidx,index);
                }
                else if(root->children[idx]->slen>n){
                    root->children[idx]->slen=n;
                    root->children[idx]->sidx=index;
                }
            }
            else{
                TrieNode*child=new TrieNode(word[k]);
                root->children[idx]=child;
                child->slen=n;
                child->sidx=index;
            }
            root=root->children[idx];
        }
    }

    int querySolver(TrieNode*root,string query){
        for(int k=query.size()-1;k>=0;k--){
    
            int idx=(query[k]-'a');
            
            if(root->children[idx]==NULL){
                return root->sidx;
            }
            root=root->children[idx];
        }
        return root->sidx;
    }

    public:
    TrieNode*root=new TrieNode('\0');

    void insertIntoTrie(vector<string>words){
        int minlen=INT_MAX,minidx=-1;
        for(int i=0;i<words.size();i++){
            if(minlen>words[i].size()){
                minlen=words[i].size();
                minidx=i;
            }
            else if(minlen==words[i].size()){
                minidx=min(minidx,i);
            }
            insertTries(root,words[i],i);
        }
        root->sidx=minidx;
    }
    int queryIntoTrie(string query){
        TrieNode*temphead=root;
        return querySolver(temphead,query);
    }

};

int main(){
    Trie*t=new Trie();

    vector<string>words={"abcd","bcd","xbcd"};
    vector<string>queries={"cd","bcd","xyz"};
    t->insertIntoTrie(words);
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        ans.push_back(t->queryIntoTrie(queries[i]));
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";


}