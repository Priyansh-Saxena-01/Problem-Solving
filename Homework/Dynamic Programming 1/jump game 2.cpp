#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // recursive solution 

    long long solve(int idx,vector<int>&nums){
        if(idx>=nums.size()-1) return 0;

        long long int temp=INT_MAX;

        for(int i=1;i<=nums[idx] && i+idx<nums.size() ;i++){
            temp=min(temp,1+solve(idx+i,nums));
        }
        return temp;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        return solve(0,nums);
    }
    // memoization solution

    // long long solve(int idx,vector<int>&nums,vector<int>&dp){
    //     if(idx>=nums.size()-1) return 0;

    //     if(dp[idx]!=0) return dp[idx];
    //     long long int temp=INT_MAX;

    //     for(int i=1;i<=nums[idx] && i+idx<nums.size() ;i++){
    //         temp=min(temp,1+solve(idx+i,nums,dp));
    //     }
    //     return dp[idx]=temp;
    // }
    // int jump(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //     return solve(0,nums,dp);
    // }
};