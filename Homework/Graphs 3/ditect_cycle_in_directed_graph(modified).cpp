class Solution {
  private:
    bool dfs(vector<int>adj[],vector<int>&vis,int node){
        vis[node]=2;
        
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(adj,vis,it)) return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[node]=1;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,i)) return true;
            }
        }
        return false;
    }
};