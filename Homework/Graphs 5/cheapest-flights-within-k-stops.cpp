class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>vis(n,1e9);
        //adjency list 
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        // priority queue 
        queue<pair<int,pair<int,int>>>q;
        int mini=1e9;

        //{cost,{stops,source}}
        q.push({0,{0,src}});
        vis[src]=0;

        while(!q.empty()){
            auto it=q.front();
            int cost=it.first;
            int node=it.second.second;
            int stops=it.second.first;
            q.pop();

            //check if we already reached the destination
            if(node==dst){
                mini=min(mini,cost);
            }

            //check if we exceeded the maximum stops allowed 
            if(stops>k || cost>mini) continue;
            
            for(auto ad:adj[node]){
                int newcost=ad.second;
                int newsrc=ad.first;

                if(newcost+cost<vis[newsrc] && stops <= k ){
                    vis[newsrc]=newcost+cost;
                    q.push({newcost+cost,{stops+1,newsrc}});
                }    
            }
        }
        if(mini>=1e9) return -1;
        return mini;
    }
};
