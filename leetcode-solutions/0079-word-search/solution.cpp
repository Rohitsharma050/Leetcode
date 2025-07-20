class Solution {
public:
    int n,m;
    bool solve(int i,int j,int idx,vector<vector<char>>& board, string &word,vector<vector<int>>&vis)
    {
        
        if(idx==word.length())
        return true;
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || board[i][j]!=word[idx])
        {
            return false;
        }
        vis[i][j] = 1;

        bool up = solve(i-1,j,idx+1,board,word,vis);
        bool right = solve(i,j+1,idx+1,board,word,vis);
        bool down = solve(i+1,j,idx+1,board,word,vis);
        bool left = solve(i,j-1,idx+1,board,word,vis);
        bool check = up|| down|| right|| left;
        vis[i][j] = 0; 
        
        return check;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(solve(i,j,0,board,word,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
