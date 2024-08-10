class Solution {
public:
void subset(int index,vector<int> &nums,vector<int> answer,vector<vector<int>> &ans)
{  
    if(index==nums.size())
    {
        ans.push_back(answer);
        return ;
    }
    answer.push_back(nums[index]);
    subset(index+1,nums,answer,ans);
    answer.pop_back();
    subset(index+1,nums,answer,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> answer;
        subset(0,nums,answer,ans);
        return ans;
    }
};
