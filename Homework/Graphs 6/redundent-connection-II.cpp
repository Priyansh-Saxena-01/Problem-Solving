#include<bits/stdc++.h>
using namespace std;

class dsu{
    private:
        vector<int>parent;
        vector<int>level;
    public:
        dsu(int n){
            parent.resize(n+1);
            level.resize(n+1,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int x){
            if(x==parent[x]) return x;
            return find(parent[x]);
        }
        void Union(int x,int y){
            int xParent=find(x);
            int yParent=find(y);

            if(xParent==yParent) return;

            if(level[xParent]>level[yParent]){
                parent[yParent]=xParent;
            }
            else if(level[xParent]<level[yParent]){
                parent[xParent]=yParent;
            }
            else{
                parent[yParent]=xParent;
                level[xParent]++;
            }
        }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>indegree(n+1,0);
        int suspect=-1,suspect1=-1,suspect2=-1;

        for(int i = 0; i < n; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;

            if(indegree[v] == 2) {
                suspect=v;
            }

        }
        if(suspect==-1){
            dsu graph(n);
            for(auto edge:edges){
                int u=edge[0];
                int v=edge[1];

                if(graph.find(u)==graph.find(v)) return {u,v};

                else graph.Union(u,v);
            }
        }

        for(int i=0;i<n;i++){

            int v=edges[i][1];

            if(indegree[v]==2){
                if(suspect1==-1)
                    suspect1=i;
                else 
                    suspect2=i;
            }
        }
        dsu connection(n);
        for(int i=0;i<n;i++){
            if(i==suspect2) continue;

            int u=edges[i][0];
            int v=edges[i][1];

            if(connection.find(u)==connection.find(v)){
                return {edges[suspect1][0],edges[suspect1][1]};
            }
            connection.Union(u,v);
    
        }

        return {edges[suspect2][0],edges[suspect2][1]};

    }
};
