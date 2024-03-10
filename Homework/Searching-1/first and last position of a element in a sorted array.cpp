#include<bits/stdc++.h>
using namespace std;
pair<int,int> firstLast(vector<int>nums,int key){
    pair<int,int>ans={-1,-1};
    int low=0;
    int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]==key){
            ans.first=mid;
            high=mid-1;
        }
        else if(nums[mid]<key) low=mid+1;
        else high=mid-1;
    }

    low=0;
    high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(nums[mid]==key){
            ans.second=mid;
            low=mid+1;
        }
        else if(nums[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
int main(){
    
    vector<int>nums={1,1,2,3,5,6,7,8,8};
    int key=8;
    pair<int,int>ans=firstLast(nums,key);
    cout<<ans.first<<" "<<ans.second;
}
