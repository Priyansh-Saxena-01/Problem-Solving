class Solution {
  private:
    bool dfs(vector<int>adj[],vector<int>&vis,vector<int>&path,int node){
        
        vis[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,path,it)) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),path(V,0);
        for(int i=0;i<V;i++){
            if(dfs(adj,vis,path,i)) return true;
        }
        return false;
    }
};