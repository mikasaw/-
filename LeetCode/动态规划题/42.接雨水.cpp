/*
给定n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


//1.用动态规划解决
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == NULL)
            return 0;
         int result = 0;
         int size = height.size();
         vector<int>leftMax(size),rightMax(size);
         leftMax[0] = height[0];

         for(int i = 1;i<size;i++) //从左边扫描 
         {
             leftMax[i] = max(height[i],leftMax[i-1]);          //把数组i到最左端最高的条形块高度记录下来
         }
         rightMax[size-1] = height[size-1];
         for(int i = size -2;i>=0;i--)
         {
             rightMax[i] = max(height[i],rightMax[i+1]);        //把数组i到最右端最高的条形块高度记录下来
         }
         for(int i = 1;i<size-1;i++)
         {
             result += min(leftMax[i],rightMax[i]) - height[i]; //找出左右扫描高度最小的值。
         }
        return result;
    }
};
