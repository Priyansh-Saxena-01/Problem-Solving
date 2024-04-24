int Solution::knight(int m, int n, int C, int D, int E, int F) {
    int dx[8]={2,2,-2,-2,-1,-1,1,1};
    int dy[8]={-1,1,1,-1,2,-2,2,-2};
    // remember this is a 1- based chessboard so reduce 
    //the values to fit to 0- based indexing
    C--; D--; E--; F--;
    
    // if start == destination
    if(C==E && D==F) return 0;
    
    vector<vector<int>>vis(m,vector<int>(n,0));
    queue<pair<int,int>>q;
    
    q.push({C,D});
    vis[C][D]=1;
    // two variable to keep track of level and increased cost per level
    int minDist=1,count=1;
    
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        // reduce elements for current level as they are popped
        count--;
        
        for(int k=0;k<8;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n){
                if(nr==E && nc==F && !vis[nr][nc]){
                    return minDist;
                }
                if(!vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        // if all elements of a level are popped then update 
        // count with number of elements at new level and update the minimum cost i.e +1
        if(count==0){
            minDist++;
            count=q.size();
        }
    }
    return -1;
}
