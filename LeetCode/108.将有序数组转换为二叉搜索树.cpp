将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
通过次数55,075提交次数78,929



//递归建树  
//选择组中间位置元素的左边元素作为根结点
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int right = nums.size()-1;
        return helper(0,right,nums);
        
        
    }

    TreeNode * helper(int left ,int right,vector<int>&nums)
    {
        if(left > right) return NULL;
        int p = (left + right) /2;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(left,p-1,nums);
        root->right = helper(p+1,right,nums);
        return root;
    }
};



//选择中间位置元素的右边元素作为根结点
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int right = nums.size()-1;
        return helper(0,right,nums);
        
        
    }

    TreeNode * helper(int left ,int right,vector<int>&nums)
    {
        if(left > right) return NULL;
        int p = (left + right) /2;
        if((left + right)%2 ==1) ++p;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(left,p-1,nums);
        root->right = helper(p+1,right,nums);
        return root;
    }
};



//随机选取中间位置元素的左右元素作为根结点
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int right = nums.size()-1;
        return helper(0,right,nums);
        
        
    }

    TreeNode * helper(int left ,int right,vector<int>&nums)
    {
        if(left > right) return NULL;
        int p = (left + right) /2;
        if((left + right)%2 ==1) p+= rand()%2;
        TreeNode* root = new TreeNode(nums[p]);
        root->left = helper(left,p-1,nums);
        root->right = helper(p+1,right,nums);
        return root;
    }
};
