给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


//利用队列先进先出的方法，根结点先进队， 然后左右结点进队。

class Solution {
public:
   
    vector<int > val ;                                      //存放同一层次结点的值
    queue<TreeNode*> q;                                     //存放同一结点的队列
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
      
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
       
        return ans;
    }

};

