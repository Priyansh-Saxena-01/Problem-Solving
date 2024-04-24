class Solution {
private:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&path){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)) return true;
            }
            else{
                if(path[it]) return true;
            }
        }
        path[node]=0;
        return false;
    }
public:
    bool canFinish(int num, vector<vector<int>>& p) {
        int m=p.size();
        if(m==0) return true;
        int n=p[0].size();

        vector<int>vis(num,0);
        vector<int>path(num,0);

        vector<int>adj[num];
        for(int i=0;i<m;i++){
            adj[p[i][1]].push_back(p[i][0]);
        }

        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};