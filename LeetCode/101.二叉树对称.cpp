给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。


//采用递归的方法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      return isMirror(root,root);

    }
    bool isMirror(TreeNode* t1, TreeNode*t2)
    {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL )return false;
        return (t1->val == t2->val) && isMirror(t1->left,t2->right) 
        && isMirror(t1->right,t2->left);
    }
};


//采用迭代的方法  利用队列来实现

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
     queue<TreeNode* > q ;
     q.push(root);
     q.push(root);
     while(!q.empty())
     {
         TreeNode* t1 = q.front();
         q.pop();
         TreeNode* t2 = q.front();
         q.pop();
         if(t1 == NULL && t2 == NULL ) continue;
         if(t1 == NULL || t2 == NULL )return false;
         if(t1->val != t2->val) return false;
         q.push(t1->left);
         q.push(t2->right);
         q.push(t1->right);
         q.push(t2->left);
     }
     return true;
    }
};
