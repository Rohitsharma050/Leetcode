class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int missing,repeat;
        int n = grid.size();
        int num = n*n;
        vector<int>temp(num+1,0);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
               temp[grid[i][j]]++;

            }
        }
        for(int i = 1;i<temp.size();i++)
        {
            if(temp[i]==0)
            {
                missing =i;
            }
            else if(temp[i]==2)
            {
                repeat=i;
            }
        }
        return {repeat,missing};
    }
};
