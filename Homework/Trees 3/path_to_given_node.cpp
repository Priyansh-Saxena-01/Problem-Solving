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

void path(Node*root,vector<int>temp,vector<int>&ans,int B){

    if(root==nullptr) return;
    if(root->val==B){
        temp.push_back(root->val);
        ans=temp;
        return;
    }
    temp.push_back(root->val);
    path(root->left,temp,ans,B);
    path(root->right,temp,ans,B);
}

int main(){
    Node*r= new Node(5);

    r->left= new Node(3);
    r->right= new Node(10);

    r->left->left= new Node(1);
    r->left->right= new Node(4);

    r->right->left= new Node(8);
    r->right->right= new Node(20);

    r->right->left->right= new Node(9);
    r->left->right->left= new Node(7);

    vector<int>temp,ans;
    path(r,temp,ans,7);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}