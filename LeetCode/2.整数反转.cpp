给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，因此由范围限定，最大值为2的31次方-1，最小值为负的32次方。


class Solution {
public:
    int reverse(int x)
     {
       int result  =0;
       while(x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (result > INT_MAX/10 || (result == INT_MAX/10 && pop > 7))
            return 0;
            if(result < INT_MIN/10 ||  (result == INT_MIN/10 && pop < -8))
            return 0;
            result = result*10 + pop;

        }

        return result;
    }
};


