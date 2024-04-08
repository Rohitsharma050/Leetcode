// USING UNORDERED MAP

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto i:nums){
            if(mp[i]==1) ans.push_back(i);
            else mp[i]++;
        }
        return ans;
    }
};
