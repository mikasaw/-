
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]



//使用动态规划来解答
   vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans (numRows) ;
       for(int i = 0;i <numRows;i++)
       {
           ans[i] = vector<int>(i+1,0);
           ans[i][0] =1;
           ans[i][i] =1;
       }
       if (numRows<=2)  return ans;
       for(int i= 2;i<numRows;i++)
        {
            for(int j = 1;j<i ;j++)
            {
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};
