/*
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

 

示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：
1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] 仅为 0、1 或 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
        int cnt = 0;
        int dis[10][10];
        int dir_x[4] = {0,1,0,-1};
        int dir_y[4] = {1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        memset(dis,-1,sizeof(dis));
        cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0.;i<n;i++)
        {
            for(int j = 0; j < m ;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                    dis[i][j]= 0;
                }
                else if(grid[i][j] == 1) cnt+=1;
            }
        }
        while(!q.empty())
        {
            pair<int,int> x = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int mx =x.first + dir_x[i];
                int my= x.first + dir_y[i];
                if(mx<0 || mx >=n || my<0 || my>m || ~dis[mx][my] || !grid[mx][my] ) continue;
                dis[mx][my] = dis[x.first][x.second]+1;
                q.push(make_pair(mx,my));
                if(grid[mx][my] == 1)
                 {
                     cnt -= 1;
                     ans = dis[mx][my];
                     if(!cnt) break;
                 }
            }
        }
        return cnt ? -1:ans;
    }
};




