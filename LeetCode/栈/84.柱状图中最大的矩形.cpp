
/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

示例:

输入: [2,1,5,6,2,3]
输出: 10
*/
//暴力法 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
        return 0;
        int ans =  0;
       for(int i =0;i<heights.size()-1;i++)
          for(int j = i+1;j<heights.size();j++)
          {
             int  heigh = min(heights[i],heights[j]);
              if(j == 1)
              ans = max(ans,max(heights[j],heights[i]));
              int weith = j-i+1;
              ans = max(ans,heigh*weith);
          }
        return ans;
    }



//用分而治之的办法
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       return  diver(heights,0,heights.size()-1);
    }

    int diver(vector<int >& heights,int left ,int right)
    {
        if(left > right)
        return 0;
        
        if(left = right)
        return heights[left];

        int minHeight =heights[left];
        int minIndex = left;

        for(int i = left;i<=right;i++)
        {
            if(min(minHeight,heights[i]) < minHeight)
              minHeight = heights[i];
              minIndex = i;
        }
        return max(minHeight * (right-left+1),max(diver(heights,left,minIndex-1),diver(heights,minIndex+1,right)));
    }
    
