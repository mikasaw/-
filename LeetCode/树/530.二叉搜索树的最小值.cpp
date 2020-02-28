给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。

示例 :

输入:

   1
    \
     3
    /
   2

输出:
1

解释:
最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
注意: 树中至少有2个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class Solution {
public:
   
    void dfs(TreeNode* root,int& ans,int& pre)
    {
        if (root == NULL)
         return ;

        dfs(root->left,ans,pre);
        if(pre >= 0) ans =  min(ans,root->val - pre);
        pre =root->val;
        dfs(root->right,ans,pre);     
    }

    
    int getMinimumDifference(TreeNode* root) {
        int ans = 0;
        if(root == NULL)
        return ans;
        ans = INT_MAX;
        int pre = -1;
        dfs(root,ans,pre);
        return ans;
    }
};
