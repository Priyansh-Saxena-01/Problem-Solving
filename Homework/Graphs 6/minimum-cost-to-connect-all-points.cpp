#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>
class Solution {
private:
    int primsAlgo(vector<vector<P>>&adj,int n){
        // prepared a min heap to get the smallest edge every time
        priority_queue<P,vector<P>,greater<P>>pq;
        // if a smallest edge is found dont waste time on visited nodes as 
        // they have already been reaches by a smallest path due to min heap
        vector<bool>vis(n,false);
        int pathSum=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            int weight=it.first;
            int node=it.second;
            pq.pop();

            // if already visited then dont consider it 
            if(vis[node]==true) continue;
            // if not visited then mark it visited 
            vis[node]=true;
            // add the path cost to the total cost
            pathSum+=weight;

            for(auto neighbour:adj[node]){
                int newWeight=neighbour.second;
                int newnode=neighbour.first;
                // if neighbour of the node not visited then push on to the priority queue
                if(!vis[newnode]){
                    pq.push({newWeight,newnode});
                }
            }
        }
        return pathSum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<P>>adj(n);

        // create the adjency list
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // get all the four points
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                // calculate the manhatten distance
                int distance=abs(x2-x1)+abs(y2-y1);

                // store the distance as a undirected graph with 
                // all the weights a manhatten distance between them
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
            }
        }
        // apply the prims algorithm
        return primsAlgo(adj,n);
    }
};