class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i] == '[')
            {
                check.push(s[i]);
            } 
            else
        {if(check.empty())
        {
            return false;
        }
        if(s[i]==')' && check.top()!='(')
        return false;
        else if(s[i]=='}' && check.top()!='{')
        return false;
        else if(s[i]==']' && check.top()!='[')
        return false;
        check.pop();}
        }
        return check.empty();
    }
};
