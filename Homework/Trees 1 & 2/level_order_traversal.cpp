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
vector<vector<int>>ans;
vector<vector<int>> levelOrder(TreeNode* r) {
    if(r==NULL) return {};
    vector<int>tobepushed={};
    queue<TreeNode*>q;
    q.push(r);
    q.push(NULL);
    while(!q.empty()){
        TreeNode*temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!q.empty()) q.push(NULL);
            ans.push_back(tobepushed);
            tobepushed={};
        }
        else{
            tobepushed.push_back(temp->val);
    
            if(temp->left!=NULL) q.push(temp->left);

            if(temp->right!=NULL) q.push(temp->right);
        }
    }
    return ans;
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

    levelOrder(r);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}