/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
*/

//使用双指针的方法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>::iterator p1 =nums.begin(), p2 =nums.begin()+1;
         int s = nums.size();
         if(s==0 || s == 1)
          { return s;}
         while(p2 != nums.end())
         {   
            if(*p1 == *p2)               //遇到相同的就把p2指向的值删去
            { nums.erase(p2);               
              s--;
            }
           else                          //不同就前进一步
            {
              p1++;p2++;
            }
         }
  
       return s;
    }
};
