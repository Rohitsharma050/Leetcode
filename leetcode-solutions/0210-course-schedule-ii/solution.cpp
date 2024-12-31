class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]); // b -> a
        }

        // Step 2: Compute in-degree for each course
        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int neighbor : adj[i]) {
                indeg[neighbor]++;
            }
        }

        // Step 3: Push courses with zero in-degree into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Perform BFS (Kahn's Algorithm)
        vector<int> ans;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);

            for (int neighbor : adj[course]) {
                indeg[neighbor]--;
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Check for cycles (if result size != numCourses)
        if (ans.size() != numCourses) {
            return {}; // Cycle detected
        }

        return ans;
    }
};

