class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int startingrow=0;
        int endingrow=row-1;
        int startingcol=0;
        int endingcol=col-1;
        int count=0;
        int total=row*col;
        while(count<total)
        {
            //print starting row
            for(int i=startingcol;i<=endingcol && count<total ;i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
               startingrow++;
            //print ending column
            for(int i=startingrow;i<=endingrow && count<total ;i++)
            {
                ans.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            //print ending row
            for(int i=endingcol;i>=startingcol && count<total ;i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            //print starting column
            for(int i=endingrow;i>=startingrow && count<total ;i--)
            {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
            
        }
        return ans;
    }

};
