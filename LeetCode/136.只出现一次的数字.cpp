
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4



//采用暴力法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
     map<int,int>m;
     for(int i = 0; i<nums.size();i++)
      {
          if(m.find(nums[i]) != m.end())
          {
              m.erase(m.find(nums[i]));
          }
          else 
          {
              m[nums[i]] =1;
          }
      }
      return m.begin()->first;
    }
};


//采用异或法 （x ^ x = 0 ，0 ^ x = x）
class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int ans = 0;
     for(int num :nums)
     {
         ans ^= num;
     }
     return ans;
    }
};
