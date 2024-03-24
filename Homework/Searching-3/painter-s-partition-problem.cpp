#include<bits/stdc++.h>
using namespace std;

int checker(vector<int>boards,int allowed){
    int sum=0,count=1;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]>allowed){
            count++;
            sum=boards[i];
        }
        else{
            sum+=boards[i];
        }
    }
    return count;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=0,high=0;
    
    for(int i=0;i<boards.size();i++){
        low=max(low,boards[i]);
        high+=boards[i];
    }
    while(low<=high){
        int mid=low+(high-low)/2;

        int needed=checker(boards,mid);

        if(needed<=k) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    vector<int>nums={8,6,10,3,2,7,10};
    int k=7;
    //vector<int>nums2={2,3,4,5};
    cout<<findLargestMinDistance(nums,k)<<endl;
    
}
