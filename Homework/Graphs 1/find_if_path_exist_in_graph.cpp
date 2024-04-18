class Solution {
public:
    bool dfs(int check, int s, int d, vector<int>adj[],vector<int>&vis){
        vis[s]=1;
        if(check==d) return true;
        for(auto it:adj[s]){
            if(vis[it]!=1){
                if(dfs(check,it,d,adj,vis)) return true;
            }
        }
        return s==d;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        return dfs(source,source,destination,adj,vis);
    }
};