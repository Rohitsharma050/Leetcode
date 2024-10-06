class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0 ;
        int n = nums.size();
        int i=0;
        int count = 0;
        map<int,int>mpp;
        mpp[0]=1;
        while(i<n)
        {
            sum +=nums[i];
            int target = sum-goal;
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
