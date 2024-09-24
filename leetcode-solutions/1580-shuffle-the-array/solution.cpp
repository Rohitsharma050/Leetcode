class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int mid = n;
        int i =0;
        while(i<n&&mid<2*n)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[mid]);
            mid++;
            i++;
        }
        return ans;
    }
};
