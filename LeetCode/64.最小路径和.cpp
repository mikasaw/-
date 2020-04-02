给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//二维数组的动态规划，从右下角到左上角。
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        vector<int>tmp(grid[0].size());
        vector<vector<int>> dp(grid.size(),tmp);
        for(int i= grid.size()-1;i>=0;i--){
           for(int j=grid[0].size()-1;j>=0;j--){
               if(i==grid.size()-1 && j!=grid[0].size()-1)
                   dp[i][j] = grid[i][j]+dp[i][j+1];
               else if  ( j==grid[0].size()-1 && i!=grid.size()-1)
                  dp[i][j] = grid[i][j]+dp[i+1][j];
               else if(j!=grid[0].size()-1 && i!=grid.size()-1)
                  dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
                else 
                dp[i][j]=grid[i][j];
           }
       }
       return dp[0][0];
    }
};


//一维数组的动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       vector<int>dp(grid[0].size());
       for(int i = grid.size()-1;i>=0;i--){
           for(int j = grid[0].size()-1;j>=0;j--){
               if(i==grid.size()-1 && j!=grid[0].size()-1)
                  dp[j]=grid[i][j] + dp[j+1];
               else if(j==grid[0].size()-1 && i!=grid.size()-1)
                  dp[j]=grid[i][j]+dp[j];
               else if(j!=grid[0].size()-1 && i!=grid.size()-1)
                  dp[j]=grid[i][j] + min(dp[j] ,dp[j+1]);
               else 
                  dp[j] = grid[i][j];
           }
       }
       return dp[0];
    }
};
