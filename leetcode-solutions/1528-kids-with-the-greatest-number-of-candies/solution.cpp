class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = candies[0];
        vector<bool>ans;
        for(int i:candies)
        {
            maxCandies = max(maxCandies,i);
        }
        for(int i:candies)
        {   
            int temp  = i+extraCandies;

            if(temp>=maxCandies)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
            
        }
        return ans;
    }
};
