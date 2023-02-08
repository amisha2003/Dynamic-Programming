int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;    

    for(int i=1;i<n;i++)
    {
        int fs=INT_MAX;
        int ss=dp[i-1]+abs(heights[i]-heights[i-1]);        
        if(i>1) fs=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(ss,fs);

    }

    return dp[n-1];
    
}


///// Frog Jump with K distance

int frogJump(int n,int k, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int x=INT_MAX;
        for(int j=1;j<=k;j++)
        {
            int y=INT_MAX;
            if(i-j>=0)y=dp[i-j]+abs(heights[i]-heights[i-j]);
            x=min(x,y);
        }
        dp[i]=x;
    }
    return dp[n-1];
}

