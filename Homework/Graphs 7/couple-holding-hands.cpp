#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>parent;
    int find(int x){
        if(x==parent[x]) return x;
        return find(parent[x]);
    }
    void Union(int a,int b){
        int aParent=find(a);
        int bParent=find(b);
        parent[bParent]=aParent;
    }

    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        parent.resize(n);
        // form the couples as given or as they are originally arranged
        for(int i=0;i<n;i+=2){
            parent[row[i]]=row[i];
            parent[row[i+1]]=row[i];
        }
        int counter=0;


        for(int i=0;i<n;i+=2){
            //for every correct combination check if it is already satisfied
            if(find(i)!=find(i+1)){
                // if not satisfied the increase the swap counter and join the intented
                // couples which means now one more swap will be required to settle
                // two un-matched pair of couples
                counter++;
                Union(i,i+1);
            }
        }
        return counter;
    }
};
