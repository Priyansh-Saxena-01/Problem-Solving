int dfs(int node,vector<int>adj[], int &ans){
    int maxi = 0;
    for(auto it : adj[node]){
        int nextHeight = dfs(it, adj, ans);
        ans = max(ans, maxi + nextHeight);
        maxi = max(maxi, nextHeight);
    }
    return 1 + maxi;
}
int Solution::solve(vector<int> &A) {

    vector<int>adj[A.size()];
    int root = -1;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == -1){
            root = i;
            continue;
        }
        adj[A[i]].push_back(i);

    }

    int ans = 0;
    dfs(root, adj, ans);
    return ans;

}