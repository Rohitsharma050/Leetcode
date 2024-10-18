class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int j=0;
        int i=0;
        int maxlen = 0;
        int countZeros = 0;
        while(j<size)
        {
            if(nums[j]==0)
            {
                countZeros++;
            }
            while(countZeros>k)
            {
                if(nums[i]==0)
                {
                    countZeros--;
                }
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;

        }
        return maxlen;
    }
};
