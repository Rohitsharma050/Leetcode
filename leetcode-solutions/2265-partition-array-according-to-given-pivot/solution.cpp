class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int sameelement= 0;
        int lesselement = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
            sameelement++;
            else if(nums[i]<pivot)
            lesselement++;
        }
        int highindex = sameelement+lesselement;
        int sameindex = lesselement;
        int lessindex = 0;
        vector<int>ans(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
            {
                ans[sameindex++] = nums[i];
            }
            else if(nums[i]>pivot)
            {
                ans[highindex++] = nums[i];
            }
            else
            {
                ans[lessindex++] = nums[i];
            }

        }
return ans;
    }
};
