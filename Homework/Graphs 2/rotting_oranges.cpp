class Solution {
private:
    int bfs(vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size(),minute=0;
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            bool flag=false;

            for(int i=0;i<sz;i++){

                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                
                if(row-1>=0 && grid[row-1][col]==1){
                    grid[row-1][col]=2;
                    q.push({row-1,col});
                    flag=true;
                }

                if(row+1<m && grid[row+1][col]==1){
                    grid[row+1][col]=2;
                    q.push({row+1,col});
                    flag=true;
                }

                if(col-1>=0 && grid[row][col-1]==1){
                    grid[row][col-1]=2;
                    q.push({row,col-1});
                    flag=true;
                }

                if(col+1<n && grid[row][col+1]==1){
                    grid[row][col+1]=2;
                    q.push({row,col+1});
                    flag=true;
                }
            }
            if(flag) minute++;
        }
        return minute;

    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minute=bfs(grid);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute;
    }
};