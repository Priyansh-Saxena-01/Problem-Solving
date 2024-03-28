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
int maxdepth(TreeNode*root){
    if(root==nullptr){
        return 0;
    }
    int lheight=maxdepth(root->left);
    int rheight=maxdepth(root->right);

    return 1+max(lheight,rheight);
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

    cout<<"the maximum depth of the tree :"<<maxdepth(r)<<endl;
    return 0;
}