class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> s;

        // Process each asteroid in the array
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                // Push positive asteroids to the stack
                s.push(arr[i]);
            } else {
                // Handle negative asteroids
                while (!s.empty() && s.top() > 0 && s.top() < abs(arr[i])) {
                    s.pop(); // Pop smaller positive asteroids
                }

                if (!s.empty() && s.top() == abs(arr[i])) {
                    // If same size positive and negative asteroid, destroy both
                    s.pop();
                } else if (s.empty() || s.top() < 0) {
                    // Push negative asteroid if no collision or only negative asteroids on stack
                    s.push(arr[i]);
                }
            }
        }

        // Convert the stack into a vector in the correct order
        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};


