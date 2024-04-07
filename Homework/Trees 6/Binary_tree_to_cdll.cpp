#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
  private:
  Node*prev,*head=nullptr;
  void dll(Node*curr){
      if(curr==nullptr) return;
      //left traversal 
      dll(curr->left);
      
      //putting of nodes in circular doubly linked list
      if(head==nullptr){
          head=prev=curr;
      }
      else{
          prev->right=curr;
          curr->left=prev;
      }
      prev=curr;
      
      //right traversal
      dll(curr->right);
  }
  public:
    Node *bTreeToCList(Node *root)
    {
    dll(root);
    prev->right=head;
    head->left=prev;
    return head;
    }
};