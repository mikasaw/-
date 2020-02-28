/*
给定一个二叉树，返回它的 前序 遍历。
 示例:
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



//递归遍历，前序遍历，先遍历根结点，再遍历根的左结点，后遍历根的右结点
class Solution {
public:
    vector<int>ans ;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root ==NULL)
         return ans;
        
        ans.push_back(root->val);                 //取结点的值
        preorderTraversal(root->left);            //遍历左子结点
        preorderTraversal(root->right);           //遍历右子结点
        
        return ans;
    }
};
