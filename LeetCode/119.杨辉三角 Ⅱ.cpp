给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

输入: 3
输出: [1,3,3,1]



//在118的基础上修改
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        for(int i= 0;i<rowIndex +1;i++)
        {
            ans[i] = vector<int>(i+1,0);
            ans[i][0] = 1;
            ans[i][i] = 1;
        }
        if(rowIndex+1  <= 2) return ans[rowIndex];
        for(int i =2 ;i<rowIndex +1;i++)
        {
            for(int j = 1;j<i;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans[rowIndex];
    }
};
