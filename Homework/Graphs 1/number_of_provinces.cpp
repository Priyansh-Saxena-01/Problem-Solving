class Solution {
public:
    void dfs(int i,vector<int>adj[],vector<int>&vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]!=1){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //do the traverse for all the vertices
        vector<int>vis(v,0);
        int count=0;
        for(int i=0;i<v;i++){ 
            if(vis[i]!=1){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};