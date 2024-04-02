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
int findD(Node*root,int num){
    if(root==nullptr) return 0;
    if(root->val==num) return 1;

    int x=findD(root->left,num);
    int y=findD(root->right,num);

    if(x>0 || y>0) return 1+max(x,y);
    return 0;
}
Node* LCA(Node* root,int a,int b) {
    if(root==nullptr) return 0;

    if(root->val==a || root->val==b){
        return root;
    }
    Node* x=LCA(root->left,a,b);
    Node* y=LCA(root->right,a,b);

    if(x==nullptr) return y;
    if(y==nullptr) return x;
    if(x && y) return root;

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

    int a=3,b=2;
    Node*temp=LCA(r,a,b);
    int x=findD(temp,a);
    int y=findD(temp,b);
    cout<<"distance between the node : "<<(x+y-2)<<endl;

    return 0;
}
