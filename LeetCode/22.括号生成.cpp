/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/




//使用回溯算法来求
class Solution {
public:

    vector<string> generateParenthesis(int n) {
       vector<string>ans;
        helper(ans,"",0,n);
        return ans;
    }
    void helper(vector<string>& ans ,string s,int leftnum,int n )
    {
        if(s.size() == 2*n && leftnum == n)
        {
            ans.emplace_back(s);
            return;
        }
        if(leftnum > n || s.size() > 2* n  || leftnum*2<s.size()) return;
        helper(ans,s+"(",leftnum+1,n);
        helper(ans,s+")",leftnum,n);
    }
};






//使用动态规划
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>>ans(n+1);
        ans[0].push_back("");
        for(int i = 1;i<=n;i++){
            for(int j= 0;j<i ;j++){
               for (string& s1 : ans[j]){   
                  for(string& s2 : ans[i-j-1])
                       ans[i].push_back("(" + s2 + ")"+s1);
               }
            }
        }
        return ans[n];
    }
};
