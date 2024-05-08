class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dis(m,vector<int>(n,1e9));
        pq.push({0,{0,0}});
        dis[0][0]=0;

        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();

            int dx[4]={1,0,-1,0};
            int dy[4]={0,1,0,-1};
            if(row==m-1 && col==n-1) return diff;
            for(int i=0;i<4;i++){
                int newrow=row+dx[i];
                int newcol=col+dy[i];
                if(newrow<m && newrow>=0 && newcol<n && newcol>=0){
                    int maxi=max(abs(heights[row][col]-heights[newrow][newcol]),diff);
                    if(maxi< dis[newrow][newcol]){
                        dis[newrow][newcol]=maxi;
                        pq.push({maxi,{newrow,newcol}});
                    }
                }
            }
        }
        return -1;
    }
};