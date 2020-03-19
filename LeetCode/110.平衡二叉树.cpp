给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。


//从上向下递归判断
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return abs(height(root->left) - height(root->right))< 2 && 
        isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode * root)
    {
        if(root == NULL) return -1;
        
        return 1+max(height(root->left),height(root->right));
    }
};


//从下向上的递归判断
class Solution {
public:
    bool isBalanced(TreeNode* root) {
      int height = 0;
     return BalanceHelp(root,height);
    }
    
   bool BalanceHelp(TreeNode* root, int & height)
   {
       if(root == NULL ){
           height = -1;
           return true;
       }
       int lefthight;
       int righthight;
       if(BalanceHelp(root->left,lefthight) && 
          BalanceHelp(root->right,righthight) && 
         abs(lefthight-righthight) < 2)
         {
             height = max(lefthight,righthight ) +1;
             return true;
         }
    return false;
   }

};
