#include<bits/stdc++.h>
using namespace std;

int checker(vector<int>nums,int x,int high){
    int low=0;
    while(low<=high){
        int mid=(low+high)>>1;
        if(nums[mid]>x){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
int kthSmallest(vector<vector<int>>mat, int n, int k)
{
  int low=mat[0][0],high=mat[n-1][n-1];
  while(low<=high){
      int mid=(low+high)>>1;
      int count=0;
      for(int i=0;i<n;i++){
          count+=checker(mat[i],mid,n-1);
      }
      //if(count==k) return mid;
      if(count>=k){
          high=mid-1;
      }
      else low=mid+1;
  }
  return low;
  
}
int main(){
    vector<vector<int>>matrix={{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }};
    //vector<vector<int>>matrix={};
    int k=3;
    int ans=kthSmallest(matrix,matrix.size(),k);
    cout<<ans;
    
}
