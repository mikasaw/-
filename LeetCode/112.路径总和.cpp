给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。


//利用递归的办法求解
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
      if(root == NULL ) return false;
      sum -= root->val;
      if(root->left == NULL  &&  root->right ==NULL) return (sum == 0);
     return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
   }
};



//利用迭代的方法求解
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
     if(root == NULL ) return false;
     
      stack<TreeNode * > node_stack  ;
      stack<int > sum_stack ;
      node_stack.push(root);
      sum_stack.push(sum - root->val);

      TreeNode * node;
      int currSum =0;
      while(!node_stack.empty())
      {
          node = node_stack.top();
          node_stack.pop();
          currSum = sum_stack.top();
          sum_stack.pop();
          if(node->right == NULL  && node->left ==NULL  && currSum==0) return true;

          if(node->right !=NULL)
          {
              node_stack.push(node->right);
              sum_stack.push(currSum- node->right->val);
          }

          if(node ->left != NULL)
          {
              node_stack.push(node->left);
              sum_stack.push(currSum - node->left->val);
          }
      }
      return false;
   }
 
};
