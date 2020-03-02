给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//双指针法

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        if(nums.size() <= 2)
        return  ans;
        //先排序
        sort(nums.begin(),nums.end());
        ans = nums[0] + nums[1] + nums[2];
       for(int i =0;i<nums.size();i++)
        {
            int left =i+1;
            int right =nums.size()-1;
            while(left < right)
          {
            int sum  = nums[i] + nums[left]+nums[right];
            if(abs(target-sum) < abs(target-ans))  ans =sum;
            if(sum > target)  right--;
            else if(sum < target)  left++;
            else return ans;
          }
        }
        return ans;
    }
};
