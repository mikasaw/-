/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//暴力法，先把所有链表存到数组了，后排序，再输出为新的链表
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> res;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * tmp = lists[i];
            while(tmp != NULL)
            {
                res.push_back(tmp->val);
                tmp =  tmp->next;
            }
        }
        sort(res.begin(),res.end());
       ListNode * ans = new ListNode(0);
       ListNode * frist = ans;
       for(int i =0;i<res.size();i++)
       {
           frist->next = new ListNode(res[i]);
           frist = frist->next;
       }
      ans = ans ->next;
      return ans;
    }
};




//分而治之的办法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int size = lists.size();
         if(size == 0 ) return NULL;
         return mergelist(lists,0,size-1);
    }

    ListNode * mergelist(vector<ListNode*>& lists ,int begin,int end)
    {
        if(begin == end )  return lists[begin];
        else
        {
            int minIndex = ( begin + end )/2;
            ListNode*l1 = mergelist(lists,begin,minIndex);
            ListNode*l2 = mergelist(lists,minIndex+1,end);
            ListNode* tmp = new ListNode(0);
            ListNode* cur = tmp;
            while(l1 && l2)
            {
                if(l1->val < l2->val)
                 {
                     cur->next =l1;
                     l1= l1->next;
                 }
                 else 
                 {
                     cur->next =l2;
                     l2 =l2->next;
                 }
                cur = cur->next;
            }
            cur->next =l1?l1:l2;
            return tmp ->next;
        }
    }
};

