class Solution {
public:
bool dfs(int node,vector<int>&color,vector<vector<int>>& graph)
{
    for(int i = 0;i<graph[node].size();i++)
    {
        //color is not assigned
        if(color[graph[node][i]]==-1)
        {
            color[graph[node][i]] = 1-color[node];
            if(dfs(graph[node][i],color,graph)==0)
            {
                return false;
            }
        }
        else
        {
            if(color[graph[node][i]] == color[node])
            {
                return false;
            }
        }

    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i = 0;i<n;i++)
        {
            vector<int>color(n,-1);
            color[i] = 1;
            if(!(dfs(i,color,graph)))
            {
                return false;
            }

        }
        return true;
    }
};


//bfs approach
// class Solution {
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> color(n, -1); // -1 means uncolored, 0 and 1 represent the two colors

//         for (int start = 0; start < n; ++start) {
//             // If the node is already colored, skip it
//             if (color[start] != -1) continue;

//             // Start BFS from this node
//             queue<int> q;
//             q.push(start);
//             color[start] = 0; // Assign the first color

//             while (!q.empty()) {
//                 int v = q.front();
//                 q.pop();

//                 // Traverse all neighbors of node v
//                 for (int neighbor : graph[v]) {
//                     if (color[neighbor] == -1) {
//                         // If the neighbor is not colored, color it with the opposite color
//                         color[neighbor] = 1 - color[v];
//                         q.push(neighbor);
//                     } else if (color[neighbor] == color[v]) {
//                         // If the neighbor is already colored with the same color, it's not bipartite
//                         return false;
//                     }
//                 }
//             }
//         }

//         return true; // If no conflicts, the graph is bipartite
//     }
// };

