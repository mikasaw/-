/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


*/


//可在102题的基础上进行修改。
//解法1
  class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        stack <TreeNode> q ;
        vector<int > val;
        if (root == NULL)
        return ans;
        q.push(*root);
        while(!q.empty())
        {
            int size= q.size();
            for(int i =0;i<size;i++)
           {  
               TreeNode cur = q.top();
               if(cur.right) q.push(*(cur.right));
               if(cur.left) q.push(*(cur.left));
                val.push_back(q.top().val);
                q.pop();
           }
             ans.push_back(val);
             val.clear();
        }
        return ans;
    }
};



