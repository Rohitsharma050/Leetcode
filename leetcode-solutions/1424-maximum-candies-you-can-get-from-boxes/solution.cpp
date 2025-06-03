#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
   int maxCandies(vector<int>& status, vector<int>& candies, 
               vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
               vector<int>& initialBoxes) {

    int n = status.size();
    vector<bool> visited(n, false), hasBox(n, false), hasKey(n, false);
    queue<int> q;

    for (int box : initialBoxes) {
        hasBox[box] = true;
    }

    bool progress = true;
    int total = 0;

    while (progress) {
        progress = false;
        for (int i = 0; i < n; ++i) {
            if (hasBox[i] && (status[i] || hasKey[i]) && !visited[i]) {
                // Open the box
                visited[i] = true;
                total += candies[i];
                progress = true;

                // Collect keys
                for (int k : keys[i]) {
                    hasKey[k] = true;
                }

                // Collect contained boxes
                for (int b : containedBoxes[i]) {
                    hasBox[b] = true;
                }
            }
        }
    }

    return total;
}

};

