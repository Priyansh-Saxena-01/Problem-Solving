#include<bits/stdc++.h>
using namespace std;


int vertical(vector<vector<int>>m,int target){
    int n=m[0].size(),low=0,high=m.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(m[mid][0]<=target && m[mid][n-1]>=target) return mid;

        else if(m[mid][0]>target) high=mid-1;

        else low=mid+1;
    }
    return -1;
}
bool horizontal(vector<vector<int>>m,int target,int row){
    int low=0,high=m[0].size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(m[row][mid]==target) return true;

        else if(m[row][mid]>target) high=mid-1;

        else low=mid+1;

    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row=vertical(matrix,target);
    if(row==-1) return false;
    return horizontal(matrix,target,row);
}
int main(){
    vector<vector<int>>matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=13;
    cout<<searchMatrix(matrix,target);
}