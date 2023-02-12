////Memoization

#include <bits/stdc++.h>

using namespace std;

int f(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {

  if (dp[day][last] != -1) return dp[day][last];

  if (day == 0) {
    int maxi = 0;
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }

  }

  return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector < vector < int > > & points) {

  vector < vector < int > > dp(n, vector < int > (4, -1));
  return f(n - 1, 3, points, dp);
}




///// Tabulation


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);    
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(dp[0][0],points[0][0]);

    for(int i=1;i<n;i++)
    {
        for(int last=0;last<4;last++)
        {
            dp[i][last]=0;
            for(int curr=0;curr<=2;curr++)
            {
                if(curr!=last){
                int point=points[i][curr]+dp[i-1][curr];
                dp[i][last]=max(dp[i][last],point);
                }
            }
        }
    }

return dp[n-1][3];
}


///// space optimization

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);    
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(prev[0],points[0][0]);

    for(int i=1;i<n;i++)
    {
        vector<int> temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
            for(int curr=0;curr<=2;curr++)
            {
                if(curr!=last){
                int point=points[i][curr]+prev[curr];
                temp[last]=max(temp[last],point);
                }
            }
        }
        prev=temp;
    }

return prev[3];
}
