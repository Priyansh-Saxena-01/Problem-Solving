class Solution {
private:
    bool detectCycle(int node,vector<int>adj[], vector<int>& vis,vector<int>& newNodeSet){
        vis[node]=2;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(detectCycle(it,adj,vis,newNodeSet)) return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[node]=1;
        newNodeSet.insert(newNodeSet.begin(),node);
        return false;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int m=edges.size();
        if(m==0) return 1;
        int n=edges[0].size();
        
        int nodes=colors.size();
        vector<int>vis(nodes,0);

        //prepare the adjency list
        vector<int>adj[nodes];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]); 
        }

        //detect any cycle
        vector<int>newNodeSet;
        for(int i=0;i<nodes;i++){
            if(vis[i]==0){
              if(detectCycle(i,adj,vis,newNodeSet)) return -1;
            }   
        }

        // dfs for calculating maximum color
        vector<vector<int>>rang(nodes,vector<int>(26,0));
        int maxColor=0;

        for(int it=0;it<newNodeSet.size();it++){
            int i=newNodeSet[it];
            int colorIdx=colors[i]-'a';
            rang[i][colorIdx]++;

            //calculate max color value
            maxColor=max(maxColor,rang[i][colorIdx]);

            for(auto it:adj[i]){

                for(int j=0;j<26 && i!=-1;j++){
                    if(rang[it][j]< rang[i][j]) rang[it][j]=rang[i][j];
                }
            }
        }
        return maxColor;
    }
};