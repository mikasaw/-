/*
您需要在二叉树的每一行中找到最大的值。
示例：

输入: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

输出: [1, 3, 9]
通过次数7,258提交次数12,405

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//在BFS的基础上再把每行中的最大值存起来
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       vector<int> ans;
        if(root == NULL)
         return ans;
         queue<TreeNode*>q;
         q.push(root);
        
        while(!q.empty())
        {
            int max1 =INT_MIN;                            //找个值来做比较的标准  
            int size = q.size();
            for(int i=0;i<size;i++)                       //遍历树的其中一行
            {    
                 TreeNode* cur = q.front();
                 q.pop();
                 if(cur->left) q.push(cur->left);
                 if(cur->right) q.push(cur->right);
                 max1 = max(max1,cur->val);               //找出行中的最大值           
            }
            ans.push_back(max1);                          //把最大值存入结果数组中 
        }
        return ans;
    }
};
