class Solution {
private:
    TreeNode*prev;
    TreeNode*first;
    TreeNode*last;
    void inorder(TreeNode*root){
        if(root==nullptr) return;

        inorder(root->left);
        if(prev!=nullptr && root->val<prev->val){
            if(first){
                last=root;
            }
            else{
                first=prev;
                last=root;
            }
        }
        prev=root;
        inorder(root->right);

    }
public:
    void recoverTree(TreeNode* root) {
        first=nullptr;
        last=nullptr;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,last->val);
    }
};