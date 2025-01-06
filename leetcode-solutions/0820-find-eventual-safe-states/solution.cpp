class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(int i = 0;i<n;i++)
        {
            for(auto neighbor:graph[i])
            {
                adj[neighbor].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0;i<adj[node].size();i++)
            {
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};
