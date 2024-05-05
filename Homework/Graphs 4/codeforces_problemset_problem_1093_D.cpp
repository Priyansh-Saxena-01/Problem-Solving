#include<bits/stdc++.h>
using namespace std;
#define mod 998244353;
#define sz 3e5
int c0,c1;
vector<long long>powerof2(sz,1);
vector<vector<int>>adj(sz);
vector<bool>vis(sz,false);
vector<int>color(sz,-1);

bool dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&color){
    vis[node]=true;
    for(auto it:adj[node]){
        if(color[it]==color[node]) return false;
        if(!vis[it]){
            color[it]=!color[node];
            if(color[it]) c1++;
            else c0++;
            
            if(!dfs(it,adj,vis,color)) return false;
        }
    }
    return true;
}

void solve(int n,vector<vector<int>>&adj,vector<bool>&vis,vector<int>&color){
    long long ans=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            c0=0,c1=1;
            color[i]=1;
            
            if(!dfs(i,adj,vis,color)){
                ans=0;
                break;
            }
            else{
                long long temp=(powerof2[c0]+powerof2[c1])%mod;
                ans=(ans*temp)%mod;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i=1;i<sz;i++) powerof2[i]=(powerof2[i-1]*2)%mod;
    while(t--){
        int n,m;
        cin>>n;
        cin>>m;
        for (int i = 1;i<=n;i++)adj[i].clear(),color[i] = -1,vis[i] = false;
        while(m--){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(n,adj,vis,color);
    }
}