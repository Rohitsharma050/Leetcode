class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]&1)
            {
                nums[i]=1;
            }
            else
            nums[i]=0;
        }
        map<int ,int>mpp;
        mpp[0] =1;
        int sum=0;
        int i=0;
        int count = 0;
        while(i<n)
        {
            sum +=nums[i];
            int target = sum - k;
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
