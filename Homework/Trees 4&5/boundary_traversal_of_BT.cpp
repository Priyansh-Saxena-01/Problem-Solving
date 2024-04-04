#include<bits/stdc++.h>
using namespace std;   

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void rightView(Node*root,vector<int>&ans){
    vector<int>temp;
    Node*curr=root->right;
    while(curr){
        if(curr->left || curr->right){
            temp.push_back(curr->val);
        }
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i){
        ans.push_back(temp[i]);
    }
}
void bottomView(Node*root,vector<int>&ans){
    if(root==nullptr) return;
    if(!root->left && !root->right){
        ans.push_back(root->val);
        return;
    }
    bottomView(root->left,ans);
    bottomView(root->right,ans);
}
void leftView(Node*root,vector<int>&ans){
    Node*curr=root->left;
    while(curr){
        if(curr->left || curr->right){
            ans.push_back(curr->val);
        }
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

int main(){
    Node*r= new Node(1);

    r->left= new Node(2);
    r->right= new Node(3);

    r->left->left= new Node(4);
    r->left->right= new Node(5);

    r->right->left= new Node(6);
    r->right->right= new Node(7);

    r->right->left->right= new Node(9);
    r->left->right->left= new Node(8);

    vector<int>ans1;
    if(!r) return {};
    if(!r->left && !r->right){
        ans1.push_back(r->val);
        return r->val;
    }
    ans1.push_back(r->val);
    
    leftView(r,ans1);
    bottomView(r,ans1);
    rightView(r,ans1);

    cout<<"boundary traversal of the tree : "<<endl;
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    return 0;
}
