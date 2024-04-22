class Solution {
private:
    void dfs(vector<vector<char>>&b,vector<vector<int>>&vis, int i,int j){
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]!='O'|| vis[i][j]) return;

        vis[i][j]=1;
        dfs(b,vis,i+1,j);
        dfs(b,vis,i-1,j);
        dfs(b,vis,i,j+1);
        dfs(b,vis,i,j-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        // for column wise traversal
        for(int i=0;i<n;i++){
            // first column
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(board,vis,0,i);
            }
            // last column
            if(board[m-1][i]=='O' && !vis[m-1][i]){
                dfs(board,vis,m-1,i);
            }
        }
        // for row wise traversal
        for(int i=0;i<m;i++){
            // first row
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(board,vis,i,0);
            }
            // last row
            if(board[i][n-1]=='O' && !vis[i][n-1]){
                dfs(board,vis,i,n-1);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};