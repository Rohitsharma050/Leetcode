class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Initialize the in-degree array and adjacency list
        vector<int> indeg(numCourses, 0); // To track the number of prerequisites for each course
        vector<vector<int>> adj(numCourses); // Adjacency list to represent the graph

        // Step 2: Build the graph (Adjacency List) and calculate in-degrees
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Directed edge pre[1] -> pre[0]
            indeg[pre[0]]++; // Increment in-degree of the destination course
        }

        // Step 3: Push all courses with zero in-degree into the queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Process the courses in topological order
        int processedCourses = 0; // Count of courses we are able to process
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            processedCourses++;

            // Reduce the in-degree of all neighbors of the current course
            for (int neighbor : adj[course]) {
                indeg[neighbor]--;
                // If the in-degree becomes zero, push the neighbor into the queue
                if (indeg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Check if all courses were processed
        // If all courses were processed, there is no cycle, and all courses can be finished.
        return processedCourses == numCourses;
    }
};

