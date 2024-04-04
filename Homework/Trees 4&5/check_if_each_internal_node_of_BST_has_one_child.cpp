#include<bits/stdc++.h>
using namespace std;   

bool BSThasOneChild(vector<int>nums){
    int low=INT_MIN,high=INT_MAX;
    if(nums.size()<2)  return true;
    for(int i=1;i<nums.size();i++){
        //check the node value with the range calculated
        if(nums[i]<=low || nums[i]>=high) return false;

        //decide the new ranges for the next nodes
        if(nums[i]>nums[i-1]) low=nums[i-1];
        else high=nums[i-1];
    }
    return true;
}

int main(){
    vector<int>nums={20, 10, 11, 13, 12};
    if(BSThasOneChild(nums)){
        cout<<"all the nodes in BST have only one child";
    }
    else cout<<"all nodes in the BST do not have only one child";
    return 0;
}
