给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false


//使用双指针的方法
class Solution {
public:
    bool isPalindrome(string s) {
        for(int left =0,right = s.size()-1;left<right;left++,right--)
        {
            while(!isalnum(s[left]) && left<right) left++;
            while(!isalnum(s[right]) && left<right) right--;
            if(toupper(s[left]) != toupper(s[right])) return false;
        }
        
    return true;
    }
};

