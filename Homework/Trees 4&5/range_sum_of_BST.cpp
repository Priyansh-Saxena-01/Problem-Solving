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

void rangeSumBST(Node*root,int low,int high,int&sum){
    if(root==nullptr) return;
    if(root->val<=high && root->val>=low) sum+=root->val;

    rangeSumBST(root->left,low,high,sum);
    rangeSumBST(root->right,low,high,sum);
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

    int sum=0;
    rangeSumBST(r,7,15,sum);
    cout<<"the sum of nodes in the givn range is : "<<sum;

    return 0;
}
