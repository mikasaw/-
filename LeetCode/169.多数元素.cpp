给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2


//先排序，n/2位置的元素为目标元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      return nums[nums.size()/2];
    }
};



//使用hashmap方法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     unordered_map<int,int> map;
     for(int i =0;i<nums.size();i++)
     {
         map[nums[i]]++;
         if(map[nums[i]] > nums.size()/2) return nums[i];
     }
     return -1;
    }
};


//使用投票机制
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int candidate = -1;
     int count = 0;
     for(int num:nums)
     {
         if(num == candidate) 
          count ++;
          
         else if(--count < 0)
         {
             candidate = num;
             count  =1;
         }
     }
     return candidate;
    }
};
