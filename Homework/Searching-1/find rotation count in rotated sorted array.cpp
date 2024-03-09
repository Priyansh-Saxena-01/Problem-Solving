#include<bits/stdc++.h>
using namespace std;

int rotate(vector<int>nums){
    int low=0,idx;
    int high=nums.size()-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;

        if(nums[low]<=nums[high]){
            if(nums[low]<mini){
                mini=nums[low];
                idx=low;
            }
            break;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=mini){
                mini=nums[low];
                idx=low;
            }
            low=mid+1;
        }
        else{
            if(nums[mid]<mini){
                mini=nums[mid];
                idx=mid;
            }
            high=mid-1;
        }
    }
    return idx;
}
int main(){
    
    vector<int>nums={7,8,9,1,2,3,4,5,6};
    cout<<rotate(nums);
}
