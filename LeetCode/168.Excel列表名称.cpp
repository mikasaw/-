给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
示例 1:

输入: 1
输出: "A"
示例 2:

输入: 28
输出: "AB"
示例 3:

输入: 701
输出: "ZY"

//这是一个10进制转26进制的题目
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0)
        {
            n -= 1;
            ans.push_back('A' + (n%26));
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
