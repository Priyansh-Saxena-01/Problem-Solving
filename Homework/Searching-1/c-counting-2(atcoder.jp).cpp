#include<bits/stdc++.h>
using namespace std;
vector<int> minsearch(int N,vector<int>nums,int Q, vector<int>queries){
    vector<int>ans;
    for(int i=0;i<queries.size();i++){
        int q=queries[i];
        int low=0;
        int high=nums.size()-1;
        int count=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=q){
                count=nums.size()-mid;
                high=mid-1;
            }
            else low=mid+1;

        }
        ans.push_back(count);
    }
    return ans;
}
int main(){
    
    int N=5;
    vector<int>nums={804289384,846930887,681692778,714636916,957747794};
    int Q=5;
    vector<int>queries={424238336,719885387,649760493,596516650,189641422};
    sort(nums.begin(),nums.end());
    vector<int>ans=minsearch(N,nums,Q,queries);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
