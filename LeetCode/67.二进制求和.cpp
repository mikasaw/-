给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



//
class Solution {
public:
    string addBinary(string a, string b) {
        string ans ;
        int flag = 0;
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||flag;--i,--j){
            int x =i<0?0:a[i]-'0';
            int y =j<0?0:b[j]-'0';
            int sum = (x+y+flag)%2;
            flag = (x+y+flag)/2;
            ans.insert(0,1,sum+'0');
        }
        return ans;
    }
};
