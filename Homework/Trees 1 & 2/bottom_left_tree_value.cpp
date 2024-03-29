#include<bits/stdc++.h>
using namespace std;   
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int height(TreeNode*root){
    if(root==nullptr) return 0;
    return 1+max(height(root->left),height(root->right));
}

int leftView(TreeNode*root,int lvl,vector<int>&taken){
    if(root==NULL){
        return 0;
    }
    if(taken[lvl]==INT_MAX){
        taken[lvl]=root->val;
    }
    return leftView(root->left,lvl+1,taken)+leftView(root->right,lvl+1,taken);

}

int main(){
    TreeNode*r= new TreeNode(2);

    r->left= new TreeNode(3);
    r->right= new TreeNode(10);

    r->left->left= new TreeNode(1);
    r->left->right= new TreeNode(4);

    r->right->left= new TreeNode(8);
    r->right->right= new TreeNode(20);

    r->right->left->right= new TreeNode(9);
    r->left->right->left= new TreeNode(7);

    int n=height(r);
    vector<int>taken(n,INT_MAX);
    leftView(r,0,taken);
    cout<<"the bottom left integer is : "<<taken[n-1];
    return 0;
}