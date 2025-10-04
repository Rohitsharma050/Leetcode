class Solution {
public:
void solve(vector<int>& nums,vector<int>&temp,vector<int>&vis,vector<vector<int>>&ans){
    if(temp.size()==nums.size())
    {
        ans.push_back(temp);
        return;
    }

    for(int i = 0;i<nums.size();i++)
    {
        if(vis[i])
        continue;
        if(i>0 && nums[i]==nums[i-1] && vis[i-1]==false )
        continue;
        temp.push_back(nums[i]);
        vis[i] = 1;
        solve(nums,temp,vis,ans);
        temp.pop_back();
        vis[i] = 0;

    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        solve(nums,temp,vis,ans);
        return ans;
    }
};
