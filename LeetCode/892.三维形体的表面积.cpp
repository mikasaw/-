892. 三维形体的表面积
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

 

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
 

提示：

1 <= N <= 50
0 <= grid[i][j] <= 50


//逐步计算每个位置上的正方体的表面积
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N =  grid.size();
        int ans = 0;
        for(int i =0;i<N;i++){
            for(int j =0;j<N;j++){
                ans += i-1>=0?max(grid[i][j] - grid[i-1][j],0):grid[i][j]; //计算上面露出的表面积
                ans += i+1<N?max(grid[i][j]-grid[i+1][j],0):grid[i][j];    //计算下面露出的表面积
                ans += j-1>=0?max(grid[i][j] - grid[i][j-1],0):grid[i][j]; //计算左边露出的表面积
                ans += j+1<N?max(grid[i][j] - grid[i][j+1],0):grid[i][j];  //计算右边露出的表面积
                ans += 2*(grid[i][j]>0?1:0);                               // 顶部、低部的表面积
            }
        }
        return ans;
    }
};
