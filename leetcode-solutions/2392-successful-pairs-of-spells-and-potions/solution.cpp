class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         vector<int> ans;
         int n = spells.size();
         sort(potions.begin(),potions.end());
         for(int i = 0;i<n;i++)
         {
            long long target = ceil((double)success / spells[i]);
            int totalPair = potions.end() - lower_bound(potions.begin(),potions.end(),target);
            ans.push_back(totalPair);

         }
         return ans;
    }
};
