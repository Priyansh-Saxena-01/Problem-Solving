#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode*zero,*one;

    TrieNode(){
        zero=one=nullptr;
    }
};

class Trie{
    private:
    void insertTries(TrieNode*root,int num){
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(bit==0){
                if(root->zero==nullptr){
                    root->zero=new TrieNode();   
                }
                root=root->zero;
            }
            else{
                if(root->one==nullptr){
                    root->one=new TrieNode();
                }
                root=root->one;
            }
        }
    }
    int querySolver(TrieNode*curr,int num){
        int ans=0;
        TrieNode*root=curr;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(bit==1){
                if(root->zero!=nullptr){
                    ans+=(1<<i);
                    root=root->zero;
                }
                else root=root->one;
            }
            else{
                if(root->one!=nullptr){
                    ans+=(1<<i);
                    root=root->one;
                }
                else root=root->zero;
            }
        }
        return ans;
    }

    public:
    TrieNode*root=new TrieNode();

    void insertIntoTrie(vector<int>nums){
        for(auto i:nums){
            insertTries(root,i);
        }
    }
    int query(vector<int>nums){
        int ans=0;
        for(auto i:nums){
            ans=max(ans,querySolver(root,i));
        }
        return ans;
    }
};

int main(){
    Trie*t=new Trie();
    vector<int>nums={3,10,5,25,2,8};
    t->insertIntoTrie(nums);
    cout<<"the largest possible XOR is : "<<t->query(nums);

}