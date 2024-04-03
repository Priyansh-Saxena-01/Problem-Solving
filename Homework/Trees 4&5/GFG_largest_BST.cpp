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
class ds{
    public:
    int sum;
    bool isBst;
    int low;
    int high;

    ds(): sum(0),isBst(true),low(INT_MAX),high(INT_MIN) {};
};
int maxi=0;
ds largestBst(Node*root){
    if(root==nullptr){
        return ds();
    }
    ds leftds=largestBst(root->left);
    ds rightds=largestBst(root->right);
    
    if(!leftds.isBst || !rightds.isBst || root->val <= leftds.high || root->val >= rightds.low){
        ds temp;
        temp.sum=max(leftds.sum,rightds.sum);
        temp.isBst=false;
        return temp;
    }
    ds temp;
    temp.isBst=true;
    temp.sum=leftds.sum+rightds.sum+1;
    
    temp.low=(root->left)?leftds.low:root->val;
    temp.high=(root->right)?rightds.high:root->val;
    
    return temp;
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

    ds ans=largestBst(r);
    cout<<"the largest BST size is : "<<ans.sum;

}
