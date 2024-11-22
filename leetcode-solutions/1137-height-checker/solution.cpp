class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int size = heights.size();
        vector<int> sorted(heights.begin(),heights.end());
        sort(sorted.begin(),sorted.end());
        int count =0;
        for(int i = 0;i<size;i++)
        {
            if(sorted[i]!=heights[i])
            count++;
        }
        return count;
    }
};
