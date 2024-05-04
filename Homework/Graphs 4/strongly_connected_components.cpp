class Solution
{
    private:
    void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[node]=true;
        
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    void dfsForSCC(int node,vector<bool>&vis,vector<int>adjNew[]){
        vis[node]=true;
        for(auto it:adjNew[node]){
            if(!vis[it]){
                dfsForSCC(it,vis,adjNew);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool>vis(V,false);
        stack<int>st;
        // prepare the original  ordering of nodes in callStack
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        // reverse the nodes of he graph in a sepearte adjency list
        vector<int>adjNew[V];
        for(int i=0;i<V;i++){
            vis[i]=false;  // a side task to just re-initialize the visited vector for use again
            for(auto it:adj[i]){
                adjNew[it].push_back(i);
            }
        }
        int components=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                components++;
                dfsForSCC(node,vis,adjNew);
            }
        }
        return components;
    }
};