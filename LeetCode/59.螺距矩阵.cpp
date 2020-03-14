给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//在前面54题的基础上进行结题
//把取出变成放入

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>>ans(n);
      for(int i = 0;i<ans.size();i++)
      {
          ans[i].resize(n);
      }
     int upper = 0, downer = n-1;
     int left = 0,right = n-1;
     int num = 1;
     while(upper <= downer && left <= right)
     {
         for(int i = left;i<= right ;i++)
         {
             ans[upper][i] = num++;
         }
         upper++;
         if(upper > downer)  break;

         for(int i = upper;i<=downer;i++)
         {
             ans[i][right]=num ++;
         }
         right --;
         if(left > right) break;

        for(int i = right;i>=left;i--)
         {
            ans[downer][i]= num++;
         }
        downer--;

        for(int i = downer;i>=upper;i--)
        {
            ans[i][left] = num++;
        }
        left++;

     }
     return ans;

    }
};
