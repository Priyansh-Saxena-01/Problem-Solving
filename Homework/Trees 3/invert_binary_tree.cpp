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

Node* invertTree(Node* root) {
    if(root==nullptr) return root;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp!=nullptr){
            q.push(temp->left);
            q.push(temp->right);
            swap(temp->left,temp->right);
        }
    }
    return root;
}
void inorder(Node*ans){
    if(ans==nullptr) return;
    inorder(ans->left);
    cout<<ans->val<<" ";
    inorder(ans->right);
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

    inorder(r);
    Node*ans=invertTree(r);
    cout<<endl;
    inorder(ans);
    return 0;
}