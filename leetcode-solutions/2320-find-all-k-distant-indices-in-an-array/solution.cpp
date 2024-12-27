class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n  = nums.size();
        vector<int>keyindex;
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            if(nums[i]==key)
            keyindex.push_back(i);
        }
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<keyindex.size();j++)
            {
                if(abs(i-keyindex[j])<=k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
