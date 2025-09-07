class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n&1)
        {
            for(int i = -n/2;i<=n/2;i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            for(int i = -n/2;i<=n/2;i++)
            {
                if(i==0)
                continue;
                ans.push_back(i);
            }
        }
        return ans;
    }
};
