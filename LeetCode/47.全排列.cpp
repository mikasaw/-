给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//在46题的基础上增加去重
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        perm(ans,nums,0);
        return ans;
    }

   
    void perm(vector<vector<int>>&ans,vector<int>&nums,int i )
    {
        if(i == nums.size()-1)
        {
           
          ans.push_back(nums);
           return;
        }

        for(int j = i;j<nums.size();j++)
        {
            if(i == j ){                //不需要交换的递归
                perm(ans,nums,i+1);
                continue;
            }
             
            int k ;
            for(k = j-1;k>=i;k--){
                if(nums[k] == nums[j]) break;
            }
            if(k!=i-1) continue;  //重复了，跳过这个数
            //正常的交换递归
             swap(nums[i],nums[j]);
             perm(ans,nums,i+1);
             swap(nums[i],nums[j]);
        }
        
    }
};
