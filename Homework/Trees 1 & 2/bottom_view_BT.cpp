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
vector<int>ans;
int bottomView(TreeNode*r){
    if(r==NULL){
        return 0;
    }
    if(r->left==NULL && r->right==NULL){
        ans.push_back(r->val);
        return 1;
    }

    int x=bottomView(r->left);
    int y=bottomView(r->right);
    return x+y;

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

    cout<<"Number of bottom view node are :"<<bottomView(r)<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}