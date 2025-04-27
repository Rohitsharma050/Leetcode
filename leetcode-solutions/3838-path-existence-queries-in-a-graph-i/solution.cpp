class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
    
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                unite(i, i+1);
            }
        }
        
        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(find(q[0]) == find(q[1]));
        }
        return ans;
    }
};

