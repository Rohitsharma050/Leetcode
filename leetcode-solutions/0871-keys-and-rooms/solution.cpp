class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>>& rooms)
{
    vis[node] = 1;
    for(auto neigh:rooms[node])
    {
        if(!vis[neigh])
        {
            dfs(neigh,vis,rooms);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vector<bool>vis(n,0);
        dfs(0,vis,rooms);
        for(int i = 0;i<n;i++)
        {
            if(vis[i]==0)
            return false;
        }
        return true;
    }

};
