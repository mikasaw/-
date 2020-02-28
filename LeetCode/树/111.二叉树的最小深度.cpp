/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//和前面求二叉树的最大深度的方法差不多，不过要注意叶子结点的判断


//方法一：
class Solution {
public:
    int minDepth(TreeNode* root) {
        
         return (root==NULL)?0:(root->left == nullptr || root->right == nullptr)?(root->left ==nullptr)?minDepth(root->right)+1:minDepth(root->left)+1:
                 min(minDepth(root->left),minDepth(root->right))+1;
 
    }
};



//方法二：
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) 
        return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (root->left == nullptr || root->right == nullptr){
            return left == 0 ? right+1 : left +1;
        } else{
            return min(left, right) + 1;
        }
    }
};

