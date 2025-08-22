class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maximpact = 0;
        int n = arr.size();
        int ans= 0;
        for(int i = 0;i<n;i++)
        {
            maximpact = max(maximpact,arr[i]);
            if(maximpact==i)
            {
                ans++;
            }
        }
        return ans;
    }
};
