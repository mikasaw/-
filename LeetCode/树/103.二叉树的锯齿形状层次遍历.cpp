/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/




// 先层次遍历，再反转需要反转的数组 
class Solution {
public:
   
    void reverse(vector<int>&val)
    {
        int n = val.size()-1;
        for(int i = 0;i<n;i++)
        {
            int tmp= val[i];
            val[i]= val[n-i];
            val[n-i] = tmp;
        }
    }




    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int >> ans;
       if(root ==NULL) 
       return ans;
       queue<TreeNode*>q;
       vector<int > val;
       q.push(root);
       while(!q.empty())
       {
           int size = q.size();
           for(int i = 0;i< size;i++)
           {
               auto cur = q.front();
               q.pop();
               val.push_back(cur->val);
               if(cur->left) q.push(cur->left);
               if(cur->right) q.push(cur->right);

           }
          ans.push_back(val);
          val.clear();
       }
       
       for(int i =1;i<ans.size()-2;i+=2)
       {
           reverse(ans[i]);
       }

      return ans;
        
    }
     
};
