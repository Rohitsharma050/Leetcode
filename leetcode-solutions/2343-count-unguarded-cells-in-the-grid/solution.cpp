class Solution {
public:
void markGuarded(int row,int col,vector<vector<int>>& grid)
{
    //up
    for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == 1 || grid[r][col] == 2) break;
            grid[r][col] = 0;
        }

    //down
      for (int r = row + 1; r < grid.size(); r++) {
            if (grid[r][col] == 1 || grid[r][col] == 2) break;
            grid[r][col] = 0;
        }
    //left
     for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == 1 || grid[row][c] == 2) break;
            grid[row][c] = 0;
        }
    //right
     for (int c = col + 1; c < grid[row].size(); c++) {
            if (grid[row][c] == 1 || grid[row][c] == 2) break;
            grid[row][c] = 0;
        }
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //guard==2
        //wall==1
        //guarded==0
        //unguarded==-1
        vector<vector<int>>grid(m,vector<int>(n,-1));
        for(int i = 0 ;i<guards.size();i++)
        {
            //guard==2
            grid[guards[i][0]][guards[i][1]] = 2;
        }
         for(int i = 0 ;i<walls.size();i++)
        {
            //walls==1
            grid[walls[i][0]][walls[i][1]] = 1;
        }
        for(int i = 0;i<guards.size();i++)
        {
            markGuarded(guards[i][0],guards[i][1],grid);
        }

        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == -1) count++;
            }
        }
        return count;
        
    }
};
