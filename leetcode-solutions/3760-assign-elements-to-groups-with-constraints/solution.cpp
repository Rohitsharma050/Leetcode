#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        vector<int> ans;
        unordered_map<int, int> indexmp;

        // Step 1: Store the first occurrence index of each element
        for (int i = 0; i < elements.size(); i++) {
            if (indexmp.find(elements[i]) == indexmp.end()) {
                indexmp[elements[i]] = i;
            }
        }

        // Step 2: Process each group
        for (int i = 0; i < n; i++) {
            int minidx = INT_MAX;
            int num = groups[i];

            // Step 3: Find minimum index using divisors
            for (int j = 1; j * j <= num; j++) {
                if (num % j == 0) {
                    if (indexmp.find(j) != indexmp.end())
                        minidx = min(minidx, indexmp[j]);

                    int comdiv = num / j;
                    if (comdiv != j && indexmp.find(comdiv) != indexmp.end())
                        minidx = min(minidx, indexmp[comdiv]);
                }
            }

            // Step 4: Store result
            ans.push_back(minidx == INT_MAX ? -1 : minidx);
        }

        return ans;
    }
};

