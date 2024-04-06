class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;
        if(root==p || root==q) return root;

        TreeNode*leftptr=nullptr,*rightptr=nullptr;
        if(p->val < root->val || q->val < root->val)
            leftptr=lowestCommonAncestor(root->left,p,q);
        if(p->val > root->val || q->val > root->val)
            rightptr=lowestCommonAncestor(root->right,p,q);

        if(leftptr && rightptr) return root;
        return (!leftptr)?rightptr:leftptr;
    }
};