/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//滑动窗口法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
      int size  = s.size();
      if(size == 0)
      return 0;
      if(size ==1)
      return 1;
      int maxlen=0;
      int left = 0;
      unordered_set<char> set;
      for(int i =0;i<size;i++)
      {
          while( set.find(s[i]) !=set.end() )
            {
                set.erase(s[left]);
                left++;
            }
            maxlen= max(maxlen,i-left+1);
            set.insert(s[i]);
      }

     return maxlen;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
      int size  = s.size();
      if(size == 0)
      return 0;
      if(size ==1)
      return 1;
      int start = 0,end = 0,len =0,ans =0;
      
      while(end < size)
      {
          char tmp = s[end];
          for(int i =start;i<end;i++)
          {
              if(tmp == s[i])
              {
                  start = i+1;
                  len = end -start;
                  break;
              }
          }
          end++;
          len++;
          ans = max(ans,len);
        
      }
      return ans;
   
    }
};

