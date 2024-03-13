#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& stalls,int gap, int k){
    int last=stalls[0];
    k--;
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=gap){
            last=stalls[i];
            k--;
        }
        if(k==0) return true;
    }
    return false;
}
int solve(int n, int k, vector<int> &stalls) {

    int sizeOfStalls=stalls.size();
    sort(stalls.begin(),stalls.end());
    int maxsize=stalls[n-1]-stalls[0];
    if(n==2 || k==2) return maxsize;
    
    int low=1,high=stalls[n-1],ans=INT_MIN;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isPossible(stalls,mid,k)){
            ans=max(ans,mid);
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
int main(){
    int k=3;
    vector<int>stalls={1,2,4,8,9};
    cout<<solve(stalls.size(),k,stalls);
}