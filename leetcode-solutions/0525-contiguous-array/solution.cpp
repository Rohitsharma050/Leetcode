class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        int sum = 0;
        mpp[0]=-1;
        int len=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                sum-=1;
            }
            else
            {
                sum+=1;
            }
            if(mpp.find(sum)!=mpp.end())
            {
                len = max(len,i-mpp[sum]);
            }
            else
            mpp[sum]=i;
        }
        return len;
    }
};
