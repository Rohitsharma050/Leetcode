class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        map<int,int>mpp;
        mpp[temp[0]] = 0;
        for(int i=1;i<n;i++)
        {
            if(temp[i]>temp[i-1])
            {
                mpp[temp[i]] = i;
            }
            
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(mpp[nums[i]]);
        }
        return ans;
    }
};
