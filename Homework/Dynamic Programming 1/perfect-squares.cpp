#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int m=sqrt(n);
        vector<vector<int>>dp(m,vector<int>(n+1,0));

        for(int i=0;i<=n;i++) dp[0][i]=i;

        for(int i=1;i<m;i++){
            int num=(i+1)*(i+1);
            for(int j=0;j<=n;j++){
                if(j-num>=0){
                    dp[i][j]=min(dp[i][j-num]+1,dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[m-1][n];
    }
};