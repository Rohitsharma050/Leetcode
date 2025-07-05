class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int ans = 0;
        for(auto it:mp){
            if(it.second==it.first)
            {
                ans = max(ans,it.first);
            }
        }
        return ans==0?-1:ans;
    }
};
