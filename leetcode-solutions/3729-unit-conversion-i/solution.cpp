class Solution {
public:
    const int mod = 1e9+7;
    
    void dfs(int node, vector<int>& vis, vector<int>& ans, vector<vector<pair<int,int>>>& adj) {
        vis[node] = 1;
        for (auto& [neighbor, factor] : adj[node]) {
            if (!vis[neighbor]) {
                ans[neighbor] = (1LL * ans[node] * factor) % mod;
                dfs(neighbor, vis, ans, adj);
            }
        }
    }
    
    vector<int> baseUnitConversions(vector<vector<int>>& conv) {
        int n = 0;
        for (auto &it : conv) {
            n = max({n, it[0], it[1]});
        }
        n = n + 1;
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : conv) {
            int source = it[0];
            int target = it[1];
            int fact = it[2];
            adj[source].push_back({target, fact});
        }
        
        vector<int> ans(n, 0);
        ans[0] = 1;
        vector<int> vis(n, 0);
        
        dfs(0, vis, ans, adj);
        
        return ans;
    }
};

