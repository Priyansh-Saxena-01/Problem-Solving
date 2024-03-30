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

void calculatePaths(Node*root,long long target,int& sum){
    if(root==nullptr) return;
    target-=root->val;
    if(target==0){
        sum++;
    }
    calculatePaths(root->left,target,sum);
    calculatePaths(root->right,target,sum);
}
void path(Node*root,int target,int&count){
    if(root==nullptr) return;
    int sum=0;
    calculatePaths(root,target,sum);
    count+=sum;
    path(root->left,target,count);
    path(root->right,target,count); 
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
    path(r,8,count);
    cout<<count;
    return 0;
}