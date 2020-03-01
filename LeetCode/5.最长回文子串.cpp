给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//采用中心法，从中间往两边寻找
class Solution {
public:
    string longestPalindrome(string s) {    
        if(s.size() == 0 || s.size() ==1)
        return s;
        int start = 0,end = 0,len =0;
        for(int i= 0;i<s.size();i++)
        {   
            int len1 = Center(s,i,i);       //中心为一个的情况
            int len2 = Center(s,i,i+1);     //中心为两个的情况
             len =max(max(len1,len2),len);
            if(len > end-start+1)
            {
                start = i - (len-1)/2;      //开始点在中心点的左边
                end = i+ len/2 ;            //尾部在中心点的右边
            }
        }
        return s.substr(start,len);

    }
 int Center(string s , int left,int right)      //找到最长子串
 {
     int  L = left ; 
     int R  = right;
     while(L>=0 &&  R < s.length() &&  s[L] == s[R])
     {
         L--;
         R++;
     }
    return R-L -1;
 }
};
