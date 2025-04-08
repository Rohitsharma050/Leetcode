class Solution {
public:
void solve(int i,int n,int sum,int target, vector<int>temp,
        vector<vector<int>>&ans,vector<int>&nums)
        {
            if(sum==target)
            {
               ans.push_back(temp);
                return;
            }
            if(sum>target)
            {
                return;
            }
            if(i>=n)
            {
                return;
            }
            
            temp.push_back(nums[i]);
            solve(i+1,n,sum+nums[i],target,temp,ans,nums);
            temp.pop_back();
            while(i+1<n && nums[i]==nums[i+1])
            i++;
            solve(i+1,n,sum,target,temp,ans,nums);
        }
    vector<vector<int>> combinationSum2(vector<int>&nums, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        int sum = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,sum,target,temp,ans,nums);
        return ans;

    }
};
