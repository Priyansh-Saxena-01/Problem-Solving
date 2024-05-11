class Solution {
private:
    void dijkstra(int src,vector<pair<int,int>>adj[],vector<int>&result){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        result[src]=0;
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int newnode=it.first;
                int newcost=it.second;

                if((cost+newcost)<result[newnode]){
                    result[newnode]=cost+newcost;
                    pq.push({result[newnode],newnode});
                }
            }
        }
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        int m=edges.size();
        //prepare the adjency list
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>start(n,1e9),end(n,1e9);
        dijkstra(0,adj,start);
        dijkstra(n-1,adj,end);
        int ans=start[n-1];

        vector<bool>result(m);
        for(int i=0;i<m;i++){
            if((start[edges[i][0]]+end[edges[i][1]]+edges[i][2]) == ans ||
            (start[edges[i][1]]+end[edges[i][0]]+edges[i][2]) == ans ) result[i]=true;
            else result[i]=false;
        }
        return result;
    }
};