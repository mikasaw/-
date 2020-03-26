49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

//用hashmap来进行比较
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int sub = 0;
        string tmp ;
        unordered_map<string,int> m;
        for(auto str:strs) {
            tmp = str;
            sort(tmp.begin(),tmp.end());
            if(m.count(tmp)){
                ans[m[tmp]].push_back(str);
            }
            else {
                vector<string> vec(1,str);
                ans.push_back(vec);
                m[tmp] = sub ++;
            }
        }
        return ans;
    }
};
