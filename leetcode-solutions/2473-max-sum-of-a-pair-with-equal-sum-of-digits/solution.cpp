class Solution {
public:
int getDigitSum(int n)
{
    int sum = 0;
    while(n!=0)
    {
        int digit = n%10;
        sum+=digit;
        n = n/10;
    }
    return sum;
}
    int maximumSum(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int>mp;
        int result = -1;
        for(int i =0;i<size;i++)
        {
            int digitsum = getDigitSum(nums[i]);
            if(mp.find(digitsum)!=mp.end())
            {
                result = max(mp[digitsum]+nums[i],result);
                mp[digitsum] = max(mp[digitsum],nums[i]);
            }
            else
            {
                mp[digitsum] = nums[i];
            }
        }
        return result;
    }
};
