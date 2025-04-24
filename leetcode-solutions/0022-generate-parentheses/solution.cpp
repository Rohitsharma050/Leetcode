class Solution {
public:
void solve(int l,int r,int n,string s,vector<string>&ans)
{
    if(s.length()==2*n)
    {
        ans.push_back(s);
        return ;
    }
    if(l<n)
    {  
        s.push_back('(');
        solve(l+1,r,n,s,ans);
        s.pop_back();
    }
    
    if(r<l)
    {
        s.push_back(')');
        solve(l,r+1,n,s,ans);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
};
