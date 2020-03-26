给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//一次性旋转4个位置
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n = matrix.size();
     for(int i =0;i<(n+1)/2;i++){
         for(int j = 0;j<n/2;j++){
             int tmp = matrix[n-1-j][i];
             matrix[n-1-j][i] = matrix[n-1-i][n-j-1];
             matrix[n-1-i][n-j-1] = matrix[j][n-1-i];
             matrix[j][n-1-i] = matrix[i][j];
             matrix[i][j] = tmp;
         }
      }
    }
};



//先存放到队列里面去，再拿出来
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        queue<int> q;
        for(int i = 0;i<matrix.size();i++){
            for(int j =0;j<matrix[i].size();j++){
                q.push(matrix[i][j]);
            }
        }
       
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = 0;j<matrix[0].size();j++){
                matrix[j][i] = q.front();
                q.pop();
            }
        }
        
    }
};
