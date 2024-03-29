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

vector<vector<int>> lvltraversal(Node*r){
    if(r==NULL) return {};
    vector<vector<int>>ans={};
    vector<int>tobepushed={};
    queue<Node*>q;
    q.push(r);
    q.push(NULL);
    while(!q.empty()){
        Node*temp=q.front();
        q.pop();
        if(temp==NULL){
            if(!q.empty()) q.push(NULL);
            ans.push_back(tobepushed);
            tobepushed={};
        }
        else{
            tobepushed.push_back(temp->val);
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
       
    }
    return ans;
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

    vector<vector<int>>out={};

    cout<<"it is the level order traversal of the tree :"<<endl;
    out=lvltraversal(r);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}