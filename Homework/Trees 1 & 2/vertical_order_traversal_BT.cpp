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

void verticalTraversal(Node*root,int row, int col,map<int,map<int,vector<int>>>&mp){
    if(root==nullptr) return;
    mp[col][row].push_back(root->val);

    verticalTraversal(root->left,row+1,col-1,mp);
    verticalTraversal(root->right,row+1,col+1,mp);
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

    map<int,map<int,vector<int>>>mp;
    verticalTraversal(r,0,0,mp);

    vector<vector<int>>ans;

    for(auto it=mp.begin();it!=mp.end();it++){
        vector<int>temp1;
        for(auto it2=(it->second).begin();it2!=(it->second).end();it2++){
            vector<int>temp2=it2->second;
            sort(temp2.begin(),temp2.end());
            temp1.insert(temp1.end(),temp2.begin(),temp2.end());
        }
        ans.push_back(temp1);
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}