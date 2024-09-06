class Solution {
public:
void getAns(int index,vector<int>& candidates,int target,vector<int>& ds,vector<vector<int>>& ans)
{
    if(target==0)
    {   ans.push_back(ds);
        return ;
    }
      if (index >= candidates.size() || target < 0) {
            return;
        }
    if(candidates[index]<=target)
    {
        ds.push_back(candidates[index]);
    
        getAns(index,candidates,target-candidates[index],ds,ans);
        ds.pop_back();
    }
    getAns(index+1,candidates,target,ds,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        getAns(0,candidates,target,ds,ans);
        return ans;
    }
};
