class Solution {
public:
bool solve(int i,string s, unordered_set<string>&wordDict, vector<int>&dp)
{
    if(i==s.length())
    return 1;
    if(wordDict.find(s)!=wordDict.end())
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    for(int l=1;l<s.length();l++)
    {
        string temp = s.substr(i,l);
        if(wordDict.find(temp)!=wordDict.end() && solve(i+l,s,wordDict,dp))
        {
            return dp[i] = 1;
        }
    }
    return dp[i] = 0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> dict(wordDict.begin(), wordDict.end());
         vector<int>dp(s.length()+1,-1);
        int n = s.length();
        return solve(0,s,dict,dp);

    }
};
