#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>nums,int sum,int window){
    int maxSum=0,i=1,j=window;
    for(int k=0;k<window;k++) maxSum+=nums[k];
    if(maxSum>sum) return false;
    while(j<nums.size()){
        maxSum+=(nums[j]-nums[i]);
        if(maxSum>sum) return false;
        i++;j++;
    }
    return true;
}
int subSum(vector<int>nums,int s){
    int n=nums.size();
    int low=1,high=n;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(checker(nums,s,mid)){
            ans=max(ans,mid);
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int>nums={1,3,4,2};
    int s=7;
    cout<<subSum(nums,s);
    
}
