#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>nums,int days,int m,int k){
    int n=nums.size(),count=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=days){
            
            count++;
            if(count==k){
                m--;
                if(m==0) return true;
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    if(m!=0) return false;
    return true;
}
int minDays(vector<int>bloomDay,int m,int k){
    int n=bloomDay.size();
    //if(flowers>n) return -1;

    int low=1,high=0;
    for(int i=0;i<bloomDay.size();i++) high=max(high,bloomDay[i]);
    int mini=INT_MAX-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(checker(bloomDay,mid,m,k)){
            mini=min(mini,mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(mini==INT_MAX-1) return -1;
    return mini;

}
int main(){
    vector<int>nums={1,10,3,10,2};
    int m=3,k=1;
    cout<<minDays(nums,m,k);
    
}
