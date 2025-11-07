class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<int>indegree(n);
        vector<vector<int>>adj(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(auto node:adj[i])
            {
                indegree[node]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh:adj[node])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

};
