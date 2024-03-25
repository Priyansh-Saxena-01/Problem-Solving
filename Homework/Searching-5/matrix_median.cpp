#include<bits/stdc++.h>
using namespace std;

int checker(vector<int>m,int med,int high){
    int low=0;
    
    while(low<=high){
        int mid=(high+low)>>1;
        if(m[mid]>med){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int Median(vector<vector<int>> &matrix)
{
    int m=matrix.size(),n=matrix[0].size(),num=(m*n)>>1;
    int low=1,high=matrix[m-1][n-1];
    while(low<=high){
        int mid=(high+low)>>1;
        
        int count=0;
        for(int i=0;i<m;i++){
            count+=checker(matrix[i],mid,n-1);
        }

        if(count<=num){
            low=mid+1;
        }
        else high=mid-1;
    }
    return low;
}
int main(){
    vector<vector<int>>matrix={{1, 3, 4},{2, 4, 5},{3, 4, 10}};
    //vector<vector<int>>matrix={};
    int ans=Median(matrix);
    cout<<ans;
    
}
