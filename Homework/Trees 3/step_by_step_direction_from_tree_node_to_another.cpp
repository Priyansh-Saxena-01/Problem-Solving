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

Node* LCA(Node* root,int a,int b) {
    if(root==nullptr) return 0;

    if(root->val==a || root->val==b){
        return root;
    }
    Node* x=LCA(root->left,a,b);
    Node* y=LCA(root->right,a,b);

    if(x==nullptr) return y;
    if(y==nullptr) return x;
    return root;

}
bool findD(Node*root,int num,string&str){
    if(root==nullptr) return false;
    if(root->val==num) return true;

    str+='L';
    bool x=findD(root->left,num,str);

    if(x) return true;
    else str.pop_back();

    str+='R';
    bool y=findD(root->right,num,str);

    if(y) return true;
    else str.pop_back();

    return false;
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

    string ans="";
    int start=2,end=3;
    Node*temp=LCA(r,start,end);

    findD(temp,start,ans);
    for(int i=0;i<ans.size();i++) ans[i]='U';

    findD(temp,end,ans);
    cout<<"path between the node is : "<<ans<<endl;

    return 0;
}
