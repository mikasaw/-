编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
  
  
 class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)  return "";

        string result = strs[0];          //先选第一个字符串为公共前缀
        for(int i =1;i< strs.size();i++)
        {
            while (strs[i].find(result) != 0)
            {   
                if( result == "")
                return "";

                result = result.substr(0,result.length()-1);        //
            }

        }

        return result;
    }
};
