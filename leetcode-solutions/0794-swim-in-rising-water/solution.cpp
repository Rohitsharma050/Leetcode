class Solution {
public:
typedef pair<int,pair<int,int>> P;
bool isValid(int i,int j,int n)
{
    return i<n && j<n && i>=0 && j>=0;
}
vector<vector<int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<P,vector<P>,greater<P>>q;
        q.push({grid[0][0],{0,0}});//{time,i,j};
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        
        while(!q.empty())
        {
            auto it = q.top();
            q.pop();
            int currCost = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i==n-1 && j==n-1)
            return currCost;
            for(int k = 0;k<4;k++)
            {
                int newi = i+dir[k][0];
                int newj = j+dir[k][1];
                if(isValid(newi,newj,n))
                {
                    if( max(currCost,grid[newi][newj])<cost[newi][newj])
                    {cost[newi][newj] = max(currCost,grid[newi][newj]);
                    q.push({cost[newi][newj],{newi,newj}});}
                    
                }
            }
            
            
        }
        return -1;
    }
};
