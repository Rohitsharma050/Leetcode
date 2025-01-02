class Solution {
public:
 int nextrow[4] ={-1,0,1,0};
 int nextcol[4] = {0,1,0,-1};
 int n,m;
 bool valid(int i,int j)
 {
    return i>=0 && i<n && j>=0 && j<m;
 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        if(image[sr][sc]==color)
        return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int incolor = image[sr][sc];
        image[sr][sc] = color;
        //int incolor = image[sr][sc];
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int row = r+nextrow[i];
                int col = c+nextcol[i];
                if(valid(row,col) &&image[row][col]==incolor )
                {
                    image[row][col] =color;
                    q.push({row,col});
                }
            }

        }
        return image;
    }
};
