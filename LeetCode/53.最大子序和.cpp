给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//暴力法求解
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = nums[0], i ,j,max1=nums[0],max2=nums[0];
      
         for (i=0;i<nums.size();i++)
         {
              sum = nums[i];
            for (j=i+1;j<nums.size();j++)
            {  
                 max1 = max(max1,sum);
                 sum += nums[j];
                 max1 = max(max1,sum);
            }
            max1 = max(max1,sum);
            max2 = max(max1,max2);
        }
      return max2;  
    }
};


//动态规划法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp (nums.size());
        if(nums.size() == 0)
         return 0;
         dp[0] = nums[0];
        int max1 = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = max(nums[i],dp[i-1]+nums[i]);
            max1 = max(dp[i] ,max1);
        }
      return  max1;
    }
};


//动态规划再简化
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
         return 0;
         int dp =nums[0];
        int max1 = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp = max(nums[i],dp+nums[i]);
            max1 = max(dp ,max1);
        }
      return  max1;
    }
};

