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


//2.先用102题的方法解答，再反转数组
class Solution {
public:

 void reverse(vector<vector<int>>& ans){                   //数组反转函数
        int len = ans.size()-1;
        int mid = len / 2;
        int i = 0;
        while(i<=mid){
            ans[i].swap(ans[len-i]); 
            i++;
        }
    }

    queue<TreeNode*>q;
    vector<int >val;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      
        vector<vector<int>>ans;
        if(root == NULL)
           return ans;
        q.push(root);
        while(!q.empty())
        { 
            int size = q.size();                                    
            for(int i =0;i<size;i++)                        //轮流取出同一层次的结点
            {
                auto cur = q.front();       
                q.pop();
                val.push_back(cur->val);                    //把每个结点的值压入值数组
                if(cur->left) q.push(cur->left);            //左右结点存在的话就压入队列
                if(cur->right) q.push(cur->right);\
                
            }
            ans.push_back(val);                             //把同一层次的值放入二维数组    
            val.clear();                                    //把值数组清空，进入下一层次。
        }
        reverse(ans);
        return ans;
    }
};






