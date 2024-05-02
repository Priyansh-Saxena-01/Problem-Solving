class Solution {
private:
    void dfs(int node,vector<int>adj[],vector<int>&temp,vector<bool>&vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                temp.push_back(it);
                dfs(it,adj,temp,vis);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<vector<int>>ans(n);
        
        // adjency list for parents
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<int>temp;
            vector<bool>vis(n,false);
            
            dfs(i,adj,temp,vis);
            sort(temp.begin(),temp.end());
            ans[i]=temp;
        }
        return ans;
    }
};