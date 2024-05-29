#include<stdio.h>
#include <vector>
using namespace std;

class dsu{
    private:
        vector<int>parent;
        vector<int>level;
    public:
        dsu(int n){
            parent.resize(n+1);
            level.resize(n+1,0);
            for(int i=1;i<=n;i++) parent[i]=i;
        }

        void Union(int x, int y){
            int xParent=find(x);
            int yParent=find(y);

            if(xParent==yParent) return;

            if(level[xParent]>level[yParent]) parent[yParent]=xParent;
            else if(level[xParent]<level[yParent]) parent[xParent]=yParent;
            else{
                parent[yParent]=xParent;
                level[xParent]++;
            }
        }

        int find(int x){
            if(x==parent[x]) return x;
            return find(parent[x]);
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu redundant(n);

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            if(redundant.find(u)==redundant.find(v)) return {u,v};

            redundant.Union(u,v);
            
        }
        return {-1,-1};
    }
};