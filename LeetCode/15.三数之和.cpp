/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

//双指针法加上去重复操作

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        if(size <= 2)
           return ans;
        sort(nums.begin(),nums.end());
       for(int i = 0;i<size -2 ;i++)
       {
           int tmp = nums[i];
           if(tmp > 0)
               break;
           int val =  0-  tmp;
           int left = i+1;
           int right = size -1;
           while(left< right)
           {
               int leftval = nums[left];
               int rightval = nums[right];
               if(left + right == val)
               {vector<int>tmpvec{tmp,left,right};
                ans.push_back(tmpvec);
                while(left < right && nums[left] == leftval)    //除去重复数字
                {
                     left++;
                }
                while(left<right && nums[right] == rightval)   //除去重复数字
                {
                    right--;
                }
               }
               else  if (leftval + rightval < tmp)
                {
                    left ++;
                }
                else if(leftval + rightval> tmp)
                {
                    right--;
                }
                
           }
           while(i + 1 < size -2 && nums[i] == nums[i+1])
                {
                    i++;
                }
       }
        return ans;
    }
};
