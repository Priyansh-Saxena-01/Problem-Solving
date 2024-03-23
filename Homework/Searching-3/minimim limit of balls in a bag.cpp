#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>nums,int maxOperations, int balls){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%balls==0) count+=(nums[i]/balls)-1;
        else count+=(nums[i]/balls);

        if(count>maxOperations) return false;
    }
    return true;
}
int limit(vector<int>nums, int maxOperations){
    int low=1,high=0;
    int ans=0;

    for(int i=0;i<nums.size();i++){
        high=max(high,nums[i]);
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(nums,maxOperations,mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
        
    }
    return ans;

}
int main(){
    vector<int>nums={2,4,8,2};
    int maxOperations=4;
    //vector<int>nums2={2,3,4,5};
    cout<<limit(nums,maxOperations)<<endl;
    
}
