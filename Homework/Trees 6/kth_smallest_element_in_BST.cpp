/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int&k) {
        if(root==nullptr) return -1;

        int leftside=kthSmallest(root->left,k);
        k--;
        if(k==0) return root->val;
        int rightside=kthSmallest(root->right,k);

        return max(leftside,rightside);
    }
};