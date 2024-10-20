class Solution {
public:
    bool parseBoolExpr(string s) {
        
        int n = s.length();
        stack<char> st;
        int i = 0;
        while(i<n)
        {   
            if (s[i] == '(' || s[i] == 'f' || s[i] == 't' || s[i] == '|' || s[i] == '!' || s[i] == '&') {
                st.push(s[i]);
            } 
            else if(s[i]==')')
            {   int check0 = 0;
                int check1 = 0;
                while(st.top()!='(' && !st.empty())
                {
                    if(st.top()=='f')
                    {
                        check0 =1;
                    }
                    if(st.top()=='t')
                    {
                        check1 = 1;
                    }
                    st.pop();

                }
                //pop opening bracket
                st.pop();
                char op = st.top();
                //pop operator
                st.pop();
                // Evaluate the expression based on the operator
                if (op == '!') {
                    st.push(check0 ? 't' : 'f');
                } 
                else if (op == '&') {
                    st.push(check0 ? 'f' : 't');
                } 
                else if (op == '|') {
                    st.push(check1 ? 't' : 'f');
                }
                
            }
            
            i++;
        }
        return st.top() == 't';
    }
};
