class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(101,0);
        int maxFreq = 0;
        for(int i = 0;i<n;i++)
        {
            freq[nums[i]]++;
            maxFreq = max(maxFreq,freq[nums[i]]);
        }
        int count = 0;
        for(int i = 0;i<=100;i++)
        {
            if(freq[i]==maxFreq)
            {
                count+=freq[i];
            }

        }
        return count;


    }
};
