/*
给定一个二叉树，返回它的中序 遍历。
示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//中序遍历，就是先遍历左结点，再遍历根结点，后面遍历右结点。
class Solution {
public:
    vector<int >ans;

    vector<int> inorderTraversal(TreeNode* root) {
       if(root == NULL)
        return ans;
      inorderTraversal(root->left);           //先遍历左结点
      ans.push_back(root->val);               //取结点的值
      inorderTraversal(root->right);          //再遍历右结点

       return ans;
    }
};
