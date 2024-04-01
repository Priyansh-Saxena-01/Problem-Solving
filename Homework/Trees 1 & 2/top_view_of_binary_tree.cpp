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

void topView(Node*root,int lvl, int rank, map<int,pair<int,int>>&mp){

    if(root==nullptr) return;

    if(mp.find(rank)==mp.end() || (mp.find(rank)!=mp.end() && mp[rank].first>lvl)){
        mp[rank]={lvl,root->val};
    }
    topView(root->left,lvl+1,rank-1,mp);
    topView(root->right,lvl+1,rank+1,mp);
}
int main(){
    Node*r= new Node(1);

    r->left= new Node(2);
    r->right= new Node(4);

    r->left->left= new Node(3);
    r->left->right= new Node(40);

    r->right->left= new Node(80);
    r->right->right= new Node(5);

    r->right->left->right= new Node(9);
    r->left->right->left= new Node(7);

    vector<int>ans;
    map<int,pair<int,int>>mp;
    topView(r,0,0,mp);
    cout<<"Top view of the binary tree is : "<<endl;
    for(auto it:mp){
        cout<<it.second.second<<" ";
    }
    return 0;
}
