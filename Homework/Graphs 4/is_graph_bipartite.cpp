class Solution {
private:
    bool bfs(int node,vector<vector<int>>&graph,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int n=q.front();
            q.pop();

            for(auto it:graph[n]){
                if(vis[it]==0){
                    if(vis[n]==1){
                        q.push(it);
                        vis[it]=2;
                    }
                    else{
                        q.push(it);
                        vis[it]=1;
                    }
                }
                else{
                    if(vis[it]==vis[n]) return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size(),n=graph[0].size();
        vector<int>vis(m,0);

        for(int i=0;i<m;i++){
            if(vis[i]==0){
                if(!bfs(i,graph,vis)) return false;
            }
        }
        return true;
    }
};