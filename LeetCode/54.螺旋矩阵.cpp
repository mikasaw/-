/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//整个矩形一圈一圈的找，从最外层到中心
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty())  return ans;

        int upper = 0 ,downer = matrix.size()-1;
        int left = 0 ,  right = matrix[0].size()-1;
        while (upper <= downer && left<= right )
        {
            for(int i = left; i<=right ;i++)             //先找本圈的上边界
            {
                ans.push_back(matrix[upper][i]);
            }
            upper ++;
            if(upper>downer) break;

            for(int i = upper ;i<=downer;i++)            //找本圈的右边界
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(right<left) break;

            for(int i = right;i>=left;i--)               //找本圈的下边界
            {
                ans.push_back(matrix[downer][i]);
            }
            downer -- ;
           

            for(int i = downer; i>=upper;i--)           //找本圈的左边界
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
