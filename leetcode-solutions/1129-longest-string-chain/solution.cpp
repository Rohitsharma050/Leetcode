class Solution {
public:
bool ispossible(string a,string b)
{
    int n = a.length();
    int m = b.length();
    if(n!=m-1)
    return false;
    int i = 0;
    int j = 0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            i++;
        }
        j++;
    }
    return i==n;
}
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
        return a.length() < b.length();
    });


    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i = n-1;i>=0;i--)
    {
        for(int prev = i-1;prev>=-1;prev--)
        {
            int nottake = dp[i+1][prev+1];
            int take  = 0;
            if(prev==-1 || ispossible(words[prev],words[i]))
            {
                take = 1+dp[i+1][i+1];
            }
            dp[i][prev+1] = max(take,nottake);
        }

    }
    return dp[0][0];
    }
};
