class Solution {
public:
void gettotalsum(int index,int n,vector<int>&nums,vector<int>&subset,int &totalsum)
{
    if(index==n)
    {
        int currentXor = 0;
        for(int i = 0;i<subset.size();i++)
        {
            currentXor = currentXor^subset[i];
        }
        totalsum +=currentXor;
        return;
    }
        subset.push_back(nums[index]);
        gettotalsum(index+1,n,nums,subset,totalsum);
        subset.pop_back();
        gettotalsum(index+1,n,nums,subset,totalsum);
}
    int subsetXORSum(vector<int>& nums) {
        vector<int>subset;
        int totalsum = 0;
        int n = nums.size();
        gettotalsum(0,n,nums,subset,totalsum);
        return totalsum;
    }
};
