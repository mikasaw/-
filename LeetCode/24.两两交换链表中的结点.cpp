*/
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。、
*/


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
        return NULL;
        if(head->next == NULL)
        return head;
        ListNode * frist = head->next;       //记录新链表的头结点
        ListNode * pre = new ListNode(0);    //记录交换两结点的先前结点
        ListNode* tmp = NULL;                //用来记录交换结点的后结点
        while(head  &&  head->next)
        {
                  
           tmp = head->next;
           head->next = tmp->next;           //前后结点交换
           tmp->next = head;
           pre->next = tmp;                  //改变先前结点得指向
           pre = head;                       //更新先前结点
           head = head->next;                //转移到下一组要交换的结点
           
        }
        return frist;
    }
};
