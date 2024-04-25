class Solution {
private:
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
        vis[node]=2;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,ans)) return true;
            }
            else{
                if(vis[it]==2) return true;
            }
        }
        vis[node]=1;
        ans.insert(ans.begin(),node);
        return false;
    }
public:
    vector<int> findOrder(int num, vector<vector<int>>& p) {
        int m=p.size();
        vector<int>ans;
        if(m==0){
            for(int i=0;i<num;i++) ans.push_back(i);
            return ans;
        }
        int n=p[0].size();
        vector<int>adj[num];
        vector<int>vis(num,0);

        for(int i=0;i<m;i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,ans)) return {};
            }
        }
        return ans;
    }
};