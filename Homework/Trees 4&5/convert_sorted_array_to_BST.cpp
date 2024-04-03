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
Node*arrToBST(vector<int>&nums,int start, int end){
    if(start>end){
        return nullptr;
    }
    int mid=(start+end)/2;
    Node*root= new Node(nums[mid]);

    Node*x=arrToBST(nums,start,mid-1);
    Node*y=arrToBST(nums,mid+1,end);

    root->left=x;
    root->right=y;
    return root;
}

void inorder(Node*root){
    if(root==nullptr) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    Node*r= new Node(1);

    r->left= new Node(2);
    r->right= new Node(3);

    r->left->left= new Node(4);
    r->left->right= new Node(5);

    r->right->left= new Node(6);
    r->right->right= new Node(7);

    r->right->left->right= new Node(9);
    r->left->right->left= new Node(8);

    vector<int>nums={1,2,3,4,5,6,7,8,9};
    Node*ans=arrToBST(nums,0,nums.size()-1);
    cout<<"the BST  formed is :"<<endl;
    inorder(ans);

}
