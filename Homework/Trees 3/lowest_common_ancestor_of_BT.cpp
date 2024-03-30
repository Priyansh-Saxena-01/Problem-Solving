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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==nullptr) return root;
    if(root==p || root==q) return root;

    Node*left=lowestCommonAncestor(root->left,p,q);
    Node*right=lowestCommonAncestor(root->right,p,q);

    if(right==nullptr) return left;
    if(left==nullptr) return right;
    return root;
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

    int count=0;
    Node*ans=lowestCommonAncestor(r,r->left->left, r->right->left->right);
    cout<<ans->val;
    return 0;
}