class Solution {
public:
typedef pair<int,pair<int,int>> P;
bool isValid(int i,int j,int n,int m)
{
    return i<n && j<m && i>=0 && j>=0;
}
vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>cost(n,vector<int>(m,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currDiff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c == m-1)
            return currDiff;
            for(int i = 0;i<4;i++)
            {
                int newr = r + dir[i][0];
                int newc = c + dir[i][1];
                if(isValid(newr,newc,n,m))
{
if (max(abs(heights[r][c] - heights[newr][newc]), currDiff) < cost[newr][newc])

                {
                    cost[newr][newc] = max(abs(heights[r][c] - heights[newr][newc]), currDiff);
                    pq.push({max(abs(heights[r][c] - heights[newr][newc]), currDiff),{newr,newc}});
                }
            }}

        }
        return -1;
        
    }
};
