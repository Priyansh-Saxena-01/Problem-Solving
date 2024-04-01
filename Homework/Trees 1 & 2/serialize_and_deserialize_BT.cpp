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

string serialize(Node* root) {
    queue<Node*>q;
    string str="";
    int i=0;
    if(root==nullptr) return str;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        if(temp!=nullptr) str+=to_string(temp->val)+',';
        else str+="#,";
        q.pop();
        if(temp){
            if(temp->left) q.push(temp->left);
            else q.push(nullptr);
            if(temp->right) q.push(temp->right);
            else q.push(nullptr);
        }
    }
    return str;
}
Node* deserialize(string str) {

    if(str.size()==0) return nullptr;
    stringstream ss(str);
    string tempstr;
    getline(ss,tempstr,',');
    Node*root=new Node(stoi(tempstr));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        //for left
        getline(ss,tempstr,',');
        if(tempstr!="#"){
            temp->left=new Node(stoi(tempstr));
            q.push(temp->left);
        }
        else temp->left=nullptr;
        //for right
        getline(ss,tempstr,',');
        if(tempstr!="#"){
            temp->right=new Node(stoi(tempstr));
            q.push(temp->right);
        }
        else temp->right=nullptr;
    }
    return root;
}
void inorder(Node*root){
    if(root==nullptr) return ;
    cout<<root->val;
    inorder(root->left);
    inorder(root->right);
}
int main(){
    Node*r= new Node(1);

    r->left= new Node(2);
    r->right= new Node(3);


    r->left->left= nullptr;
    r->left->right= nullptr;

    r->right->left= new Node(4);
    r->right->right= new Node(5);

    cout<<"inorder traversal before serialising : "<<endl;
    inorder(r);
    cout<<endl;
    cout<<"after serialization : "<<endl;
    string str=serialize(r);
    cout<<str<<endl;
    Node*newnode=deserialize(str);
    cout<<"inorder traversal after deserialization : "<<endl;
    inorder(r);
    return 0;
}
