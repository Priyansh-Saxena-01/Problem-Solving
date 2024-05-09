class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];

        // a visites matrix to store maximum probabilities on every node
        vector<double>vis(n,0.00);

        // making the adjency list along with probabilities as pair
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<int,double>>pq;
        pq.push({start_node,1});
        vis[start_node]=1;

        while(!pq.empty()){
            auto it=pq.top();
            int node=it.first;
            double prob=it.second;
            pq.pop();
            
            // if u reach the end node dont traverse furthur, it will only decrease the 
            // probaility as multiplication with a number less then 1 decreases it 
            if(node==end_node) continue;

            for(auto ad:adj[node]){
                int newnode=ad.first;
                double newprob=ad.second;
                // if a new larger probility is found then update the visited array and 
                // push the new finding into the stack
                if((prob*newprob)>vis[newnode]){
                    vis[newnode]=(prob*newprob);
                    pq.push({newnode,vis[newnode]});
                }
            }
        }
        //maximum probability for destiation node and 0.0 if not reacheable
        return vis[end_node];
    }
};