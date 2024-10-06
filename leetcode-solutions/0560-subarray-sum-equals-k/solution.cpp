class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;int count = 0;
        map<int,int>mpp;
        mpp[0]=1;
        int i=0;
        while(i<n)
        {
            sum+=nums[i];
            int target = sum-k;
            if(mpp.find(target)!=mpp.end())
            {
                count+=mpp[target];
            }
            mpp[sum]++;
            i++;
        }
        return count;
    }
};
