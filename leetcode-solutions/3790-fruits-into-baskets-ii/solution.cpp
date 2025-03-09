class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        unordered_map<int,int>mp;
        for(int i = 0;i<fruits.size();i++)
            {
                for(int j = 0;j<baskets.size();j++)
                    {
                        if(fruits[i]<=baskets[j] && mp.find(j)==mp.end())
                        {
                            mp[j]++;
                            break;
                        }
                    }
            }
        return fruits.size()-mp.size();
    }
};
