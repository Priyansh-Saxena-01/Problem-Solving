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

int diameter(Node*root,int& length){
    if(root==nullptr) return 0;

    int x=diameter(root->left,length);
    int y=diameter(root->right,length);
    length=max(length,(x+y));
    return 1+max(x,y);
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

    int len=0;
    diameter(r,len);
    cout<<len;
    return 0;
}