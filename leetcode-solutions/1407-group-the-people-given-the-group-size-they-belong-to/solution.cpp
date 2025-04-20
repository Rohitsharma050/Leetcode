class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        int n = groupSizes.size();
        vector<vector<int>>res;
        for(int i = 0;i<n;i++)
        {
           if(mp[groupSizes[i]].size()==groupSizes[i])
           {
             res.push_back(mp[groupSizes[i]]);
             mp[groupSizes[i]].clear();
           }
           mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size()==groupSizes[i])
           {
             res.push_back(mp[groupSizes[i]]);
             mp[groupSizes[i]].clear();
           }
        }
        // for(auto it:mp)
        // {
        //     res.push_back(it.second);
        // }
        return res;
    }
};
