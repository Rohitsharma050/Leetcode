class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(char stone:stones)
        {
            mp[stone]++;
        }
        for(char jewel:jewels)
        {
            if(mp.find(jewel)!=mp.end())
            {
                ans+=mp[jewel];
            }
        }
    return ans;
    }
};
