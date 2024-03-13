#include<bits/stdc++.h>
using namespace std;

long long calculate(int mid,int n,int m){
    long long product=1;
    while(n--){
        product*=mid;
        if(product>m) break;
    }
    return product;
}
int NthRoot(int n, int m){
    if(m==1) return 1;
    if(n==1) return m;
    int low=1;
    int high=m/2;
    while(low<=high){
        
        int mid=low+(high-low)/2;
        long long num=calculate(mid,n,m);
    
        if(num==m) return mid;
        if(num<m) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    
    cout<<NthRoot(7,78125);
    
}
