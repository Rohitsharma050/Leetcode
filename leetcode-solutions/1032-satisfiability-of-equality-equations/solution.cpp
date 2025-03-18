class disjointset {
    vector<int> parent, rank, size;

public:
    disjointset(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = findparent(parent[x]);
    }

    void unionSize(int x, int y) {
        int x_parent = findparent(x);
        int y_parent = findparent(y);
        if (x_parent == y_parent) {
            return;
        }
        if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& eq) {  
        // Vector to store characters, but it's unused, so it can be removed
        vector<char> mp;  

        int n = eq.size();  // Get the number of equations in the input

        // Create a Disjoint Set (Union-Find) with size 300 (to cover all lowercase English letters)
        disjointset ds(300);  

        // First, process all equations of type "a==b" to merge connected components
        for (auto it : eq) {  
            if (it[1] == '=') {  // If equation is of the form "a==b"
                int n1 = it[0] - 'a';  // Convert character to integer index (0-25 for 'a' to 'z')
                int n2 = it[3] - 'a';  // Convert the second character in the equation
                ds.unionSize(n1, n2);  // Merge the sets of n1 and n2
            }
        }

        bool ans = true;  // Variable to store the final result (default is true)

        // Now, process all equations of type "a!=b" to check for contradictions
        for (auto it : eq) {  
            if (it[1] == '!') {  // If equation is of the form "a!=b"
                int n1 = it[0] - 'a';  // Convert first character to index
                int n2 = it[3] - 'a';  // Convert second character to index
                if (ds.findparent(n1) == ds.findparent(n2)) {  
                    // If both variables have the same parent (they are in the same set),
                    // then "a!=b" is not possible, so return false
                    ans = false;
                    break;  // No need to check further, return false immediately
                }
            }
        }

        return ans;  // Return the final result
    }
};


