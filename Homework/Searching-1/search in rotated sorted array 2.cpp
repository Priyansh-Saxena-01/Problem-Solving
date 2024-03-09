#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>nums,int key){
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==key) return true;

        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
        }

        else if(nums[low]<=nums[mid]){
            if(key>=nums[low] && key<=nums[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(key>nums[mid] && key<=nums[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return false;
}

int main(){
    vector<int>nums={4,5,1,2,3};
    int key=5;
    cout<<search(nums,key);
}