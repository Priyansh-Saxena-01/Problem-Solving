#include<bits/stdc++.h>
using namespace std;

int single(vector<int>nums){
    int n=nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
        if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    
    vector<int>nums={1,1,2,2,3,3,4,4,5,5,6,7,7,8,8,9,9};
    cout<<single(nums);
    
}
