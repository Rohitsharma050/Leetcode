#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        
        vector<int> unique;
        for (auto it : mp) {
            unique.push_back(it.first);
        }
        
        int ans = 0;
        const int MOD = 1e9 + 7;
        if (unique.empty()) return 0;
        int maxele = *max_element(unique.begin(), unique.end());
        
        for (int i = 0; i < unique.size(); i++) {
            for (int k = 0; ; k++) {
                long long p = 1LL << k;
                int target = p - unique[i];
                if (target > maxele) {
                    break;
                }
                if (mp.find(target) != mp.end()) {
                    if (target == unique[i]) {
                        ans = (ans + (long long)mp[unique[i]] * (mp[unique[i]] - 1) / 2) % MOD;
                    } else if (target > unique[i]) {
                        ans = (ans + (long long)mp[unique[i]] * mp[target]) % MOD;
                    }
                }
            }
        }
        
        return ans;
    }
};
