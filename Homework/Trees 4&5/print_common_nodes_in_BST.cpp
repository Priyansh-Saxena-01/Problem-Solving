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
set<int>st;
vector<int>ans;
void findit(Node*root1){
    if(root1==nullptr) return;
    
    findit(root1->left);
    st.insert(root1->val);
    findit(root1->right);
}

void inorder(Node*root2){
    if(root2==nullptr) return;
    
    inorder(root2->left);
    if(st.find(root2->val)!=st.end()){
        ans.push_back(root2->val);
    }
    inorder(root2->right);
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
    findit(r);
    inorder(r->left);
    cout<<"the common elements are :"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}
