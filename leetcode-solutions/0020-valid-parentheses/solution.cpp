class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;
        for(int i = 0;i<n;i++){
            if(st.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')){
                return false;
            }
            else if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if((s[i]==')' && st.top()=='(') ||( s[i]=='}' && st.top()=='{')|| (s[i]==']' && st.top()=='[')){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};
