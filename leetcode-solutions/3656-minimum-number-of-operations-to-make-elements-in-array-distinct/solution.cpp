class Solution {
public:
bool findduplicate(vector<int>nums,int i,int n)
{
    unordered_map<int ,int>mp;
    for(int j = i;j<n;j++)
        {
            if(mp.find(nums[j])!=mp.end())
            {
                return true;
            }
            mp[nums[j]++];
        }
    return false;
}
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        while(i<n)
            {
                if(findduplicate(nums,i,n))
                {
                    count++;
                }
                i+=3;
            }
        return count;
    }
};
