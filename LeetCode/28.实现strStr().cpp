实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//双指针算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(),m=needle.size();
        for(int i = 0;i<n-m+1;i++)
        {  
             int j = 0;
            for(;j<m;j++)
            {
                if(haystack[i+j] != needle[j])
                break;
            }
            if(j==m) return i;

         }
      return -1;
    }
};



//kpm算法
class Solution {
public:
    vector<int> getnext(string str)   //获取next数组
    {
        int len = str.size();
        vector<int> next;
        next.push_back(-1);
        int j =0,k=-1;
        while(k<len-1)
        {
            if(k==-1 || str[j] == str[k])
            {
                j++;
                k++;
               if(str[j] != str[k])
                    next.push_back(k);
               else 
                  next.push_back(next[k]);
         
            }
            else 
            {
                k = next[k];
            }
        }
        return next;
    }

  int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int i = 0, j=0,len1=haystack.size(),len2=needle.size();
        vector<int>next;
        next = getnext(needle);
        while((i<len1) && (j<len2))
        {
            if((j==-1) || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }
        if(j==len2)
         return i-j;

    return -1;
     
    }
};



//调用String类的成员函数
class Solution {
public:
    int strStr(string haystack, string needle) {
      if(needle.empty()) return 0;
      int pos = haystack.find(needle);
      return pos;
    }
};
