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

void findCeil(Node*root,int input,int& ans){
    if(root==nullptr) return;
    if(root->val >=input){
        ans=min(ans,root->val);
    }
    if(input>root->val) findCeil(root->right,input,ans);
    else findCeil(root->left,input,ans);
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

    int input=3;
    int ans=INT_MAX;
    findCeil(r,input,ans);
    if(ans==INT_MAX) cout<<-1;
    else cout<<"the ceil value is : "<<ans;

}
