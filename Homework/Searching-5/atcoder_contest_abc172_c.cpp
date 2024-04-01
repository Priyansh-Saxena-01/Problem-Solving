#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,m,target_time,j,k;
    cin>>n>>m>>target_time;
    vector<long long> A(n+1,0),B(m+1,0);

    for(int i=1;i<=n;i++){
        long long temp=0;
        temp+=A[i-1];
        cin>>A[i];
    }

    for(int i=0;i<=n;i++){
        if(A[i]<=target_time) j=i;
    }

    for(int i=1;i<=m;i++){
        long long temp=0;
        temp+=B[i-1];
        cin>>B[i];    
    }

    for(int i=0;i<=m;i++){
        if(B[i]<=target_time) k=i;
    }
    
    int ans=0; 
    for(int i=0;i<=j;i++){ 
        if(A[i]+B[k]>target_time){
            k--;
            continue;
        }
        ans=max(ans,i+k);
    }
    cout<<ans;
    return 0;
}