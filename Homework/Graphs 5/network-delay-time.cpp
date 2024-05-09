class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>vis(n,1e9);
        int maxi=-1;

        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        vis[k-1]=0;

        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int time=it.first;
            pq.pop();

            for(auto ad:adj[node]){
                int newnode=ad.first;
                int newtime=ad.second;

                if((time+newtime)<vis[newnode]){
                    vis[newnode]=time+newtime;
                    pq.push({vis[newnode],newnode});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]>=1e9) return -1;
            maxi=max(maxi,vis[i]);
        }
        return maxi;
    }
};