#include<bits/stdc++.h>
using namespace std;
int search(vector<int>nums,int key){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){

            int mid=(high+low)/2;

            if(nums[mid]==key) return mid;

            if(nums[mid]>=nums[low]){
                if(key<nums[mid] && key>=nums[low]) high=mid;
                else low=mid+1;
            }
            else{
                if(key>nums[mid] && key<=nums[high]) low=mid+1;
                else high=mid;
            }
            
        }
        return -1;
}
int main(){
    vector<int>nums={7,8,9,10,1,2,3,4,5,6};
    int key=2;
    cout<<search(nums,key);
}
