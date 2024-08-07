class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(adj[i].empty()) ans.push_back(i);
        }
        return ans;
    }
};