class Solution {
private:
    void dfs(int node,int parent,vector<int>adj[],vector<int>&vis,int& minlen,int count){
        vis[node]=count+1;

        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0 || vis[it]>count+1){
                dfs(it,node,adj,vis,minlen,count+1);
            }
            if(vis[it]!=0 && vis[it]<count){
                minlen=min(minlen,vis[node]-vis[it]+1);
            }
        }
        return;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int minlen=2000;
        vector<int>vis(n,0);
            int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0) dfs(i,-1,adj,vis,minlen,count);
        }
        if(minlen==2000) return -1;
        return minlen;
    }
};