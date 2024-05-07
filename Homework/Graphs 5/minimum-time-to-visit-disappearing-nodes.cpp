class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        vector<bool>vis(n,false);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        set<pair<int,int>>st;
        vector<int>dist(n,1e9);
        st.insert({0,0});
        dist[0]=0;

        while(!st.empty()){
            auto it=*(st.begin());
            int distance=it.first;
            int node=it.second;
            st.erase(it);
            if(vis[node]) continue;
            else vis[node]=true;

            for(auto ad:adj[node]){
                int adjnode=ad.first;
                int adjdistance=ad.second;

                if((distance+adjdistance)< dist[adjnode]  &&  distance+adjdistance<disappear[adjnode]){
                    dist[adjnode]=distance+adjdistance;
                    st.insert({dist[adjnode],adjnode});
                }
            }
        }
        for(auto& it:dist){
            if(it>=1e9) it=-1;
        }
        return dist;
    }
};