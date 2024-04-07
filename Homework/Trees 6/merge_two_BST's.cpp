#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    private:
    vector<int>ans;
    void mergeit(vector<int>ans1,vector<int>ans2){
        int i=0,j=0;
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<ans2[j]){
                ans.push_back(ans1[i]);
                i++;
            }
            else{
                ans.push_back(ans2[j]);
                j++;
            }
        }
        while(i<ans1.size()){
            ans.push_back(ans1[i]);
            i++;
        }
        while(j<ans2.size()){
            ans.push_back(ans2[j]);
            j++;
        }
    }
    void pushtree(Node*root,vector<int>&ans){
        if(root==nullptr) return;
        pushtree(root->left,ans);
        ans.push_back(root->data);
        pushtree(root->right,ans);
    }
    
    public:
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int>ans1;
       vector<int>ans2;
      
       pushtree(root1,ans1);
       pushtree(root2,ans2);
       mergeit(ans1,ans2);
       return ans;
    }
};