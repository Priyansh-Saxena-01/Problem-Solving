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

bool hasPathSum(Node* root, int targetSum) {
    if(root==nullptr) return false;
    targetSum-=root->val;
    if(targetSum==0 && (!root->left && !root->right)) return true;

    return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
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
    if(hasPathSum(r,15)){
        cout<<"path exists";
    }
    else cout<<"path does not exist";

    return 0;
}