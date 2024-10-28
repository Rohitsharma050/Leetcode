class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> st(begin(nums),end(nums));
        int n = nums.size();
        int maxStreak = 0;
        for(int i=0;i<n;i++)
        {   long long temp = nums[i];
            int count = 0;
            while(st.find(temp)!=st.end())
            {
                count++;
                if(temp*temp>1e5)
                break;
                temp = temp*temp;
            }
            maxStreak = max(maxStreak,count);
        }
        return maxStreak<2?-1:maxStreak;
    }
};
