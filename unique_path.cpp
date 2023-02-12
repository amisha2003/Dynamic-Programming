//// memoization


class Solution {
public:

int find(int i,int j,int m,int n,vector<vector<int>> &dp)
{
    if(i<0 || j<0 || i>m-1 ||j>n-1)return 0;
    if(i==0 && j==0)return 1;
     if(dp[i][j]!=-1)return dp[i][j];
     return dp[i][j]=find(i-1,j,m,n,dp)+find(i,j-1,m,n,dp);

}

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(m-1,n-1,m,n,dp);
    }
};


//// tabulation

int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
}
