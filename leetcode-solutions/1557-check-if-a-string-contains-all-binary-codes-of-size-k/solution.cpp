class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n = s.length();
        int total = pow(2,k);
        int i = 0,j = 0;
        while(j<n)
        {
            if(j-i+1>k)
            {
                i++;
            }
            if(j-i+1==k)
            st.insert(s.substr(i,k));
            j++;
        }
        if(st.size()==total)
        return true;
        return false;
    }
};
