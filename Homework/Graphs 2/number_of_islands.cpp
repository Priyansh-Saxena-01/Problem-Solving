// using BFS in graphs 
// class Solution {
// private:
//     void bfs(vector<vector<char>>grid,vector<vector<int>>&vis,int row, int col){
//         int m=grid.size();
//         int n=grid[0].size();
//         queue<pair<int,int>>q;
//         q.push({row,col});
//         vis[row][col]=1;
//         while(!q.empty()){
//             int i=q.front().first;
//             int j=q.front().second;
//             q.pop();
//             if(i-1>=0 && grid[i-1][j]=='1' && !vis[i-1][j]){
//                 q.push({i-1,j});
//                 vis[i-1][j]=1;
//             }
//             if(i+1<m && grid[i+1][j]=='1' && !vis[i+1][j]){
//                 q.push({i+1,j});
//                 vis[i+1][j]=1;
//             }
//             if(j-1>=0 && grid[i][j-1]=='1' && !vis[i][j-1]){
//                 q.push({i,j-1});
//                 vis[i][j-1]=1;
//             }
//             if(j+1<n && grid[i][j+1]=='1' && !vis[i][j+1]){
//                 q.push({i,j+1});
//                 vis[i][j+1]=1;
//             }
//         }
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>vis(m,vector<int>(n,0));
//         int count=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(vis[i][j]!=1 && grid[i][j]=='1'){
//                     count++;
//                     bfs(grid,vis,i,j);
//                 }
//             }
//         }
//         return count;
//     }
// };


// using DFS in graphs 
class Solution {
private:
    void dfs(vector<vector<char>>&grid,int i, int j,int m,int n){
        //check for out of bound ot visisted lands or water areas
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1') return;

        //mark the land as visited
        grid[i][j]='2';

        //search for furthur lands 
        if(i+1<m) dfs(grid,i+1,j,m,n);
        if(i-1>=0) dfs(grid,i-1,j,m,n);
        if(j+1<n) dfs(grid,i,j+1,m,n);
        if(j-1>=0) dfs(grid,i,j-1,m,n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,m,n);
                }
            }
        }
        return count;
    }
};