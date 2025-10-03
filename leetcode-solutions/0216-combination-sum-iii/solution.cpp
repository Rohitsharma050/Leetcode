class Solution {
public:
void solve(int i,int target,int size,vector<int>temp,vector<vector<int>>&ans)
{
    if(target==0 && size==0)
    {
        ans.push_back(temp);
        return ;
    }
    if(i>9 || target<0 || size<0)
    return ;
    temp.push_back(i);
    solve(i+1,target-i,size-1,temp,ans);
    temp.pop_back();
    solve(i+1,target,size,temp,ans);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,n,k,temp,ans);
        return ans;
    }

};
