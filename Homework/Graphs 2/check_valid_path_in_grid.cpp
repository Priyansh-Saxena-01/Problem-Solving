class Solution {
private:
    bool isValid(vector<vector<int>>&grid,int pr, int pc, int r, int c){
        int curr=grid[r][c],prev=grid[pr][pc];
        if(curr==1){
            if(prev==2) return false;  
        }
        else if(curr==2){
            if(prev==1) return false;
        }
        else if(curr==6){
            if(prev==5) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>&grid, vector<vector<int>>&vis,int i,int j,int pr,int pc){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1) return false;

        if(pr!=-1 && pc!=-1){
            if(!isValid(grid,pr,pc,i,j)) return false;
        }

        if(i==grid.size()-1 && j==grid[0].size()-1){
            return true;
        }

        vis[i][j]=1;

        if(grid[i][j]==1) return dfs(grid,vis,i,j+1,i,j) || dfs(grid,vis,i,j-1,i,j);
        if(grid[i][j]==2) return dfs(grid,vis,i+1,j,i,j) || dfs(grid,vis,i-1,j,i,j);
        if(grid[i][j]==3) return dfs(grid,vis,i,j-1,i,j) || dfs(grid,vis,i+1,j,i,j);
        if(grid[i][j]==4) return dfs(grid,vis,i+1,j,i,j) || dfs(grid,vis,i,j+1,i,j);
        if(grid[i][j]==5) return dfs(grid,vis,i-1,j,i,j) || dfs(grid,vis,i,j-1,i,j);
        if(grid[i][j]==6) return dfs(grid,vis,i-1,j,i,j) || dfs(grid,vis,i,j+1,i,j);

        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        return dfs(grid,vis,0,0,-1,-1);
    }
};