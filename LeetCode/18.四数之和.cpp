/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


//四指针法，在前面三数之和的前提上再加一根指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int size = nums.size();
        if(size == 0)
        return ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<size-2;i++)
        {
          int tmp = nums[i];
           for( int start = i+1; start<size-2;start++)
           { int left  = start+1;
             int right = size-1;
             int val =target - tmp - nums[start];
            while(left < right)
            {
                int leftval = nums[left];
                int rightval = nums[right];
                int startval= nums[start];
                if(leftval + rightval == val)
                {
                    vector<int>vec{tmp,startval,leftval,rightval};
                    ans.push_back(vec);
                    while(left < right && nums[left] ==leftval)
                    {
                        left++;
                    }
                    while(left<right && nums[right] == rightval)
                    {
                        right --;
                    }
                }
                else if(leftval + rightval < val)
                {left ++ ;}
                else if(leftval + rightval > val)
                {
                    right--;
                }
            }
            while(nums[start] == nums[start+1] && start+1<size-2 )
                 start++;
                 
            }
            while(i+1<size-3 && nums[i] == nums[i+1])
                i++;
        }
        return ans;
        }
};

