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

bool checkit(Node*root,long mini,long maxi){
    if(root==nullptr) return true;

    if(root->val>=maxi || root->val<=mini) return false;

    return checkit(root->left,mini,root->val) && checkit(root->right,root->val,maxi);
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

    if(checkit(r,LONG_MIN,LONG_MAX)){
        cout<<"it is a valid BST";
    }
    else{
        cout<<"it is not a valid BST";
    }

    return 0;
}
