class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        int windowsize = k+1;
        int i =0 ;
        int j = 0;
        while(j<size)
        {   
                for(int x = i;x<j;x++)
                {
                    if(nums[x]==nums[j])
                    return true;
                }
                if(j-i>=k)
                i++;
            
            j++;

        }
        return false;
    }
};
