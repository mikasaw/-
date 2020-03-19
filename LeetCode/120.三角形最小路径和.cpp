给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。



//采用动态规划的方法
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
     int size = triangle.size();
     
    vector<vector<int>> dp(triangle);
     
     for(int i =size-2;i>=0;i--)
     {
         for(int j = 0;j<triangle[i].size();j++)
         {
             dp[i][j] = min(dp[i+1][j] , dp[i+1][j+1]) + triangle[i][j];
         }
     }
      return dp[0][0];
    }
};
