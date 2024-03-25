#include<bits/stdc++.h>
using namespace std;

int checker(vector<int>nums,int x,int high)
{
    int low=0;
    while(low<=high){
        int mid=(low+high)>>1;
        if(nums[mid]> x) high=mid-1;
        else low=mid+1;
    }
    return low;

}
int Median(vector<vector<int>>mat)
{ 
    int n=mat.size(),m=mat[0].size();
    int low=1,high=1e9,num=(m*n)/2;
    while(low<=high){
        int mid=(low+high)>>1;
        int count=0;

        for(int i=0;i<n;i++){
            count+=checker(mat[i],mid,m-1);
        }

        if(count>=num){
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
    int ans=Median(matrix);
    cout<<ans;
    
}
