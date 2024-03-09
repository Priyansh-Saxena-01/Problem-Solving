#include<bits/stdc++.h>
using namespace std;
int minsearch(vector<int>nums){
    int low=0;
    int high=nums.size()-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[low]<=nums[mid]){
            mini=min(mini,nums[low]);
            low=mid+1;
        }
        else{
            mini=min(mini,nums[mid]);
            high=mid;
        }
    }
    return mini;
}
int main(){
    vector<int>nums={1,2,3,4};
    int key=7;
    cout<<minsearch(nums);
}
