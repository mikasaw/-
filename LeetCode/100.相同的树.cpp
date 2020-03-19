给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false



//递归求解
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
     if(p!=NULL && q!=NULL)
       {
           return p->val == q->val &&isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
       }
    
     return p==NULL && q==NULL;
    }
};


//
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p == NULL && q == NULL )return true;
      if(p== NULL && q!= NULL)  return false;
      if(p!= NULL && q == NULL)  return false;
      if(p->val != q->val) return false;
      return isSameTree(p->left,q->left) && isSameTree(p->right , q->right);
    }
};
