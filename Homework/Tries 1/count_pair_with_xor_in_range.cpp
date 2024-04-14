#include<bits/stdc++.h>
using namespace std;
 class Node{
    public:
    Node*left;
    Node*right;
    int count;
    Node(){
        left=right=nullptr;
        count=0;
    }
 };
 
 Node*root;
 void insert(Node*root,int val){
    for(int i=14;i>=0;i--){
        int bitVal=((1<<i)&val)?1:0;
        if(bitVal){
            if(root->right==nullptr) root->right=new Node();
            root=root->right;
        }
        else{
            if(root->left==nullptr) root->left=new Node();
            root=root->left;
        }
        root->count++;
    }
 }
 int getcount(Node*root){
    if(root!=nullptr) return root->count;
    return 0;
 }

 int query(Node*root,int val,int high,int i){
    if(root==nullptr) return 0;
    if(i<0) return getcount(root);
    
    int bitVal=((1<<i)&val)?1:0;
    int bitHigh=((1<<i)&high)?1:0;

    if(bitVal){
        if(bitHigh){
            return getcount(root->right)+query(root->left,val,high,i-1);
        }
        else{
            return query(root->right,val,high,i-1);
        }
    }
    else{
        if(!bitHigh){
            return query(root->left,val,high,i-1);
        }
        else{
            return getcount(root->left)+query(root->right,val,high,i-1);
        }
    }
    return 0;  
 }

 int main(){
    vector<int>nums={1,4,2,7};
    int low=2,high=5;
    int count=0;
    root=new Node();
    for(auto i:nums){
        count+=query(root,i,high,14);
        count-=query(root,i,low-1,14);
        insert(root,i);
    }
    cout<<count;
 }