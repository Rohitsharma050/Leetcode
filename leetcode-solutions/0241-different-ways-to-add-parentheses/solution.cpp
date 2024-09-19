class Solution {
public:
vector<int> solve(string s)
{   vector<int> result;
    vector<int> left;
    vector<int> right;
    for(int i = 0;i<s.length();i++)
    {
        if(s[i]=='+' || s[i] == '-' || s[i] == '*')
        {
            left = solve(s.substr(0,i));
            right = solve(s.substr(i+1));
            for(int &x:left)
            {
                for(int &y:right)
                {
                    if(s[i]=='+')
                    {
                        result.push_back(x+y);
                    }
                    else if(s[i]=='*')
                    {
                        result.push_back(x*y);
                    }
                    else
                    {
                        result.push_back(x-y);    
                    }
                }
            }
        }
     
    }
       if(result.empty())
        {
            result.push_back(stoi(s));
        }
        return result;
}
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
