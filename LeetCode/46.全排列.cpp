给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//使用回溯法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums,ans,0);
        return ans;
    }

    void  perm(vector<int>&nums,vector<vector<int>>& ans , int i)
    {
        if( i == nums.size())
        {
            ans.push_back(nums);
            return;
        }
       for(int j = i ;j<nums.size();j++)
       {
           if(i!=j)swap(nums[i],nums[j]);
           perm(nums,ans,i+1);
           if(i!=j)swap(nums[i],nums[j]);
       }
    }
};
