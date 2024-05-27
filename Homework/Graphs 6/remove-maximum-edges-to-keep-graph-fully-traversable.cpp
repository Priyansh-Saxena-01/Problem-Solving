#include<bits/stdc++.h>
using namespace std;

class dsu{
    private:
        vector<int>level;
        vector<int>parent;
        int components;
    public:
        dsu(int n){
            // declare the datastructures in the custom constructor
            level.resize(n+1);
            parent.resize(n+1);
            components=n;
            // at first all seperate nodes are their own parents as they are considered seperate not groups
            for(int i=1;i<=n;i++) parent[i]=i;
        }
        int find(int x){
            // if some node is its own parent then it is the topmost node with no parent yet
            if(parent[x]==x) return x;
            return find(parent[x]);
        }
        void union_it(int a,int b){
            int aParent=find(a);
            int bParent=find(b);

            if(aParent==bParent) return;

            if(level[aParent]<level[bParent]){
                // if node a has a higher priority parent 
                parent[aParent]=bParent;
                level[bParent]++;
            }
            else if(level[aParent]>level[bParent]){
                // if node b has a higher priority parent 
                parent[bParent]=aParent;
                level[aParent]++;
            }
            else{
                parent[aParent]=bParent;
                level[bParent]++;
            }
            // as the nodes are joined so the total seperate components at start are reduces by 1 
            components--;
        }
        bool isSingle(){
            // to check if only a single component is left
            if(components==1) return true;
            return false;
        }

};

class Solution {
public:
    // custom comparator function on the basis of type of edge
    static bool compare(const vector<int>&nums1,const vector<int>&nums2){
        return nums1[0]>nums2[0];
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // create seperate objects for alice and bob to manage their paths seperatly
        dsu alice(n);
        dsu bob(n);

        sort(edges.begin(),edges.end(),compare);
        int totalEdges=0;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][1];
            int v=edges[i][2];
            int type=edges[i][0];

            if(type==3){
                // if type 3 edge is present check for alice as well as bob
                bool wasAdded=false;
                if(alice.find(u)!=alice.find(v)){
                    alice.union_it(u,v);
                    wasAdded=true;
                }
                if(bob.find(u)!=bob.find(v)){
                    bob.union_it(u,v);
                    wasAdded=true;
                }
                //if any edge was added then increament the total edges required
                if(wasAdded){
                    totalEdges++;
                }
            }
            else if(type==2){
                // if path is for bob the update the bob object
                if(bob.find(u)!=bob.find(v)){
                    bob.union_it(u,v);
                    totalEdges++;
                }
            }
            else{ 
                // if path is for alice then update the alice object
                if(alice.find(u)!=alice.find(v)){
                    alice.union_it(u,v);
                    totalEdges++;
                }
            }
        }
        // at the end if both alice and bob have single component left 
        // that is all comopents are joined for both alice and bob then return edges to be removed else -1 
        if(alice.isSingle() && bob.isSingle()){
            return (edges.size()-totalEdges);
        }
        return -1;
    }
};