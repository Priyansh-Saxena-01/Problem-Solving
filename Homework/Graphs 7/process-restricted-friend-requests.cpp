#include<bits/stdc++.h>
using namespace std;

class dsu{
    private:
        vector<int>parent;
    public:
        dsu(int n){
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int x){
            if(x==parent[x]) return x;
            return find(parent[x]);
        }
        void Union(int a,int b){
            int aParent=find(a);
            int bParent=find(b);

            if(aParent==bParent) return;
            parent[b]=a;
            return;
        }
        bool isConnected(int a,int b){
            return find(a)==find(b);
        }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool>ans;
        dsu graph(n);

        for(auto req:requests){
            
            int u=req[0];
            int v=req[1];

            if(graph.isConnected(u,v)){
                ans.push_back(true);
                continue;
            }

            int uParent=graph.find(u);
            int vParent=graph.find(v);
            bool flag=true;

            for(auto bound:restrictions){
                int aParent=graph.find(bound[0]);
                int bParent=graph.find(bound[1]);

                if((aParent==uParent && bParent==vParent) || (aParent==vParent && bParent==uParent)){
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
            if(flag){
                graph.Union(uParent,vParent);
            }
        }
        return ans;
    }
};
