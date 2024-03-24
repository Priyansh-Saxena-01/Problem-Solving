#include<bits/stdc++.h>
using namespace std;

int checker(map<int,int>mp,int a,int boxes)
{
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>=boxes) a--;

        if(a==0) return true;
    }
    return false;

}
int lunchboxes(vector<int> &nums, int a)
{
    if(nums.size()<a) return 0;
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    int low=1,high=nums.size(),ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(checker(mp,a,mid)){
            ans=max(ans,mid);
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
int main(){
    vector<int>nums={1, 3, 1, 3, 10, 3, 6, 6, 13};
    int k=4;
    cout<<lunchboxes(nums,k)<<endl;
    
}
