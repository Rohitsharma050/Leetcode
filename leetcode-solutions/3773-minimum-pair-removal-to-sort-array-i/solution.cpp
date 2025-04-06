class Solution {
public:
bool check(vector<int>nums)
{
    int n =nums.size();
    for(int i = 0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                return false;
            }
        }
    return true;
}
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        while(!check(nums))
            {
                int minindex = -1;
                int minsum = INT_MAX;
                for(int i = 0;i<(int)nums.size()-1;i++)
                    {
                        int temp = nums[i]+nums[i+1];
                        if(temp<minsum)
                        {
                            minsum =temp;
                            minindex = i;
                        }
                    }
                 nums[minindex] += nums[minindex + 1];
        nums.erase(nums.begin() + minindex + 1);
        ans++;
            }
        return ans;
    }
};
