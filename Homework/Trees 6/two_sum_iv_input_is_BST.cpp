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

bool check(Node*root,int num){
    if(root==nullptr) return false;
    if(root->val==num) return true;

    if(num<root->val) return check(root->left,num);
    return check(root->right,num);
}
bool inorder(Node*root,Node*node,int k){
    if(root==nullptr) return false;
    if((root->val)*2!=k && check(node,k-root->val)) return true;

    return inorder(root->left,node,k) || inorder(root->right,node,k);
}
bool findTarget(Node* root, int k) {
    Node*node=root;
    return inorder(root,node,k);
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

    int k=15;
    cout<<findTarget(r,k);

}
