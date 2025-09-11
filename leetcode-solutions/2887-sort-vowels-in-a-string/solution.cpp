class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char>vowels;
        unordered_set<char>st = {'a','e','i','o','u','A','E','O','I','U'};
        for(int i = 0;i<n;i++)
        {
            if(st.find(s[i])!=st.end()){
                vowels.push_back(s[i]);
            }
        }
        string t = "";
        int v =0;
        sort(vowels.begin(),vowels.end());
        for(int i = 0;i<n;i++)
        {
            if(st.find(s[i])==st.end())
            {
                t+=s[i];
            }
            else
            {
                t+=vowels[v];
                v++;
            }
        }
        return t;
    }
};
