给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
示例 1:
输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/set-matrix-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//先把矩阵中与0同行或同列的非零的元素改成一个标志数，后面再把标准数改为零。

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int max1 = -100000;
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int i = 0;i<r;i++)
         {
             for(int j = 0;j<c;j++)
             {
                 if(matrix[i][j] == 0)
                 {
                     for(int k=0;k<c;k++)
                     {
                        if(matrix[i][k] != 0)
                          matrix[i][k] = max1;

                     }
                     for(int k=0;k<r;k++)
                     {
                         if(matrix[k][j] != 0)
                          matrix[k][j] = max1;
                     }

                     
                 }
             }
         }

         for(int i = 0;i<r;i++)
           {
               for(int j=0;j<c;j++)
               {
                   if(matrix[i][j] == max1)
                      matrix[i][j] = 0;
               }
           }


    }
};




