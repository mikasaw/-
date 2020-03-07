给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//采用回溯加剪枝的方法

class Solution {
public:
   
    void dfs(int start ,int target)
    {   
        if(target == 0)
        {
           ans.push_back(pa);
           return;  
        }
        for(int i = start;i<candidates.size() && target - candidates[i]>=0;i++ )
        {
            pa.push_back(candidates[i]);
            dfs(i,target-candidates[i]);
            pa.pop_back();
        }

    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        dfs(0,target);
        return ans;
    }

private:
  vector<int >candidates;
  vector<vector<int >>ans;
  vector<int >pa;
};
