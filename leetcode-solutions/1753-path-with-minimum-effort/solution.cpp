class Solution {
public:
typedef pair<int,pair<int,int>> P;
bool valid(int i,int j, int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;
            int row[4] = {0,0,1,-1};
            int col[4] = {1,-1,0,0};
            for(int i = 0;i<4;i++)
            {
                int adjrow = r+row[i];
                int adjcol = c+col[i];
                if(valid(adjrow,adjcol,n,m))
                {
                    int diff = abs(heights[adjrow][adjcol]-heights[r][c]);
                    int maxdiff = max(diff,h);
                    if(maxdiff<dist[adjrow][adjcol])
                    {dist[adjrow][adjcol] = maxdiff;
                    pq.push({maxdiff,{adjrow,adjcol}});}
                }
            }
        }
        return dist[n-1][m-1];

    }
};
