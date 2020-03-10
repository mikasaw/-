83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3



//使用双指针法，在 原本的链表上就进行操作
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL || head->next == NULL)
         return head;
         ListNode*  first= head;
         ListNode *  second = head -> next;
        while (second->next != NULL)
        { 
           if(first->val ==  second->val )
             { 
                 second = second ->next;
             }

           if(first->val !=second->val)
           {
               first->next = second;
               first = first->next;
           }
        }
        if(first->val == second->val)
        {
            first->next = NULL;
        } 
      return head ;
    }
};
