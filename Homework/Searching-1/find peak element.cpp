#include<bits/stdc++.h>
using namespace std;

int peakele(vector<int>nums){
    int low=0;
    int high=nums.size()-1;
    if(high==0) return nums[high];

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid-1<0 && nums[mid]>=nums[mid+1]) return mid;
        else if(mid-1<0 && nums[mid]<=nums[mid+1]) return mid+1;

        if(mid+1>=nums.size() && nums[mid]>=nums[mid-1]) return mid;
        else if(mid+1>=nums.size() && nums[mid]<=nums[mid-1])return mid-1;

        if(nums[mid]>=nums[mid+1] && nums[mid]>=nums[mid-1]) return mid;
        
        if(nums[mid]>=nums[mid+1]){
            high=mid-1;
        }
        else if(nums[mid]<=nums[mid+1]){
            low=mid+1;
        }
    }
    return -1;
}
int main(){
    
    vector<int>nums={1,4,6};
    cout<<peakele(nums);
    
}
