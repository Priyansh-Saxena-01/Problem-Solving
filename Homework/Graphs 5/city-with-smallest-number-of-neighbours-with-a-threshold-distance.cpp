class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {

        vector<vector<int>>adj(n,vector<int>(n,1e9));
        // make the adjency matrix
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j) adj[i][j]=min(adj[i][j],(adj[i][k]+adj[k][j]));
                }
            }
        }
        int ans=0,sz=1e9;
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                    if(adj[i][j]<=dist) count++;
                }
                if(count<=sz){
                    ans=i;
                    sz=count;
                }
            }
        return ans;
    }
};