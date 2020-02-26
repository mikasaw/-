/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
    
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:
你能不将整数转为字符串来解决这个问题吗？
*/



class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x!=0))   //排序负数和最后一位为0的整数
        return false;
        int result = 0;
        while( x > result )                //当超过原来数值数位的一半，条件就会不成立         
        {
            result = result*10 + x%10;
            x = x/10;
        }
        if(result == x || result/10 == x )  //注意x为偶数或者奇数
         return true;
        else
         return false;

    }
};
