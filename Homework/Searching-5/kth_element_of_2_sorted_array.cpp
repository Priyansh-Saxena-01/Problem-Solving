#include<bits/stdc++.h>
using namespace std;

double median(vector<int>nums1,vector<int>nums2,int k){
    int n1=nums1.size(),n2=nums2.size();
    if(n1>n2) return median(nums2,nums1,k);

    int low=max(0,k-n2),high=min(k,n1);
    while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=k-mid1;

        int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];

        if(l1<=r2 && l2<=r1){
             return max(l1,l2);
        }
        if(l1>r2) high=mid1-1;
        else low=mid1+1; 
    }
    return 0;
}
int main(){
    vector<int>nums1={1,6};
    vector<int>nums2={2,3,4,5};
    int k=3;
    cout<<median(nums1,nums2,k);
    
}
