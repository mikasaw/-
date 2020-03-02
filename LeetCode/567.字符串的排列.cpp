/*
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



//用两个map来进行暴力法比较

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2)  return false;

        map<char,int>map1,map2;
        for(auto s:s1) map1[s]++;
        for(int i=0;i<len1-1;i++)map2[s2[i]]++;

        for(int i = len1-1;i<len2;i++)
        {
            map2[s2[i]]++;
            if(map2 == map1 ) return true;
            char del = s2[i-len1 +1];        //把最前面的元素给删除 再循环比较下一个
            if(! --map2[del])map2.erase(del);
        }
        return false;
    }
};
