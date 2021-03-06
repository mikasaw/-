/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 8两点。
示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:
你可以假设数组不可变。
会多次调用 sumRange 方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

1.暴力法
class NumArray {
public:
    NumArray(vector<int>& nums): num(nums) {
       
    }
    
    int sumRange(int i, int j) {
        int result= 0;
        for(i;i<=j;i++)
        {
            result +=num[i];
        }
        return result;
    }

private:
     vector<int >& num;
};




2.//用缓冲换时间的方法
    class NumArray {
public:
     
    NumArray(vector<int>& nums): num(nums) {
    
       for(int i= 1;i<num.size();i++)
       {
         num[i] = num[i]+num[i-1];
       }
    }
    
    int sumRange(int i, int j)
    {
        if(i == 0)
        return num[j];
        else 
        return num[j]-num[i-1];
    }

private:
     vector<int >& num;
};


