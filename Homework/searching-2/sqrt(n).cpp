#include<bits/stdc++.h>
using namespace std;

int sqrt(int x){
        if(x==1) return 1;
        long low=1,high=x/2,mid;
        
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid*mid==x) return mid;

            if(mid*mid<x) low=mid+1;
            else high=mid-1;
        }
        return low-1;
}
int main(){
    
    int num=66;
    cout<<sqrt(num);
    
}
