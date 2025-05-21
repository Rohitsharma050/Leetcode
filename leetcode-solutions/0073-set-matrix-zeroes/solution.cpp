class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int>row,col;
        for(int i = 0;i<n;i++)
        {
            for(int  j= 0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int r:row)
        {
            for(int i = 0 ;i<m;i++)
            {
                matrix[r][i] = 0;
            }
        }
        for(int c:col)
        {
            for(int j = 0;j<n;j++)
            {
                matrix[j][c] =0;
            }
        }
    }
};
