class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int,int>colormap;
        unordered_map<int,int>ballmap;
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballmap.find(ball)!=ballmap.end())
            {
                int previouscolor = ballmap[ball];
                colormap[previouscolor]--;
                if(colormap[previouscolor]==0)
                {
                    colormap.erase(previouscolor);
                }
            }
                ballmap[ball] = color;
                colormap[color]++;
                ans.push_back(colormap.size());
            
        }
        return ans;
    }
};
