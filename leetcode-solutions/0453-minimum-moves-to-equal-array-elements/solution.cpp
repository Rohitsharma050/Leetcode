class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans= 0;
        int size = nums.size();
        int target = *min_element(nums.begin(),nums.end());

        for(int i = 0;i<size;i++)
        {
            ans+=abs(target-nums[i]);
        }
        return ans;
    }
};
