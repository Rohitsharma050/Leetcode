class Solution {
public:
void getpermutations(int index,vector<vector<int>> &ans,vector<int> &nums)
{
    if(index==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_set<int> s;
    for(int i=index;i<nums.size();i++)
    {   if(s.find(nums[i])!=s.end())
        continue;
        s.insert(nums[i]);
        swap(nums[index],nums[i]);
        getpermutations(index+1,ans,nums);
        
        swap(nums[index],nums[i]);

    }
    
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          vector<vector<int>> ans;
        getpermutations(0,ans,nums);
        return ans;
    }
};
