class Solution {
public:
void solve(int i,int n,int curr,int &count,int maxor,vector<int>&nums)
{
    if(i==n)
    {
        if(curr==maxor)
        {
            count++;
        }
        return;
    }

    
    solve(i+1,n,curr|nums[i],count,maxor,nums);
    
    solve(i+1,n,curr,count,maxor,nums);
    
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0 ;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            maxor = maxor|nums[i];
        }
        int count = 0;
        solve(0,n,0,count,maxor,nums);
        return count;
    }
};
