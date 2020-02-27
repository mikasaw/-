/*
给定一个数组，它的第i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
     
示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
*/

//解法1：先找出数组中的最小值，然后再在找出最小值后面的最大值 ，进行相减。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int minResult = prices[0];
      int index =0;
      int val = 0;
      for(int i =1;i<prices.size()-1;i++)
      {
          if(minResult > prices[i])
           {
               index= i;                            //存储下最小值的坐标和值
               minResult = prices[i];
           }
      }
      for(int i =index+1 ;i < prices.size()-1;i++)
      {
          val = max(val,(prices[i]-prices[index]));
      }
      if(val < 0)
      return 0;
      return  val;
    }
};


//解法二，暴力法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
      for(int i=0;i<prices.size();i++)
      {
          for(int j=i+1;j<prices.size();j++)
          {
              if(result >= prices[j]-prices[i])
              continue;
              else 
                result = prices[j] -prices[i];
          }
      }
        return result;
    }
};



//3.动态规划法，使用状态机记录
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int dp[n][2];
     for(int i =0;i<prices.size();i++)
     {
         if(i == 0)
         {
             dp[i][1] = -prices[i];
             dp[i][0] = 0;
             continue;
         }
        dp[i][1]=max(dp[i-1][1],-prices[i]);
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);


     }
     return dp[n-1][0];
    }
};
