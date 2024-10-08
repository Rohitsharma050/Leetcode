class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char ,char>mpp1,mpp2;
        for(int i=0;i<s.size();i++)
        {
            if((mpp1.find(s[i])!=mpp1.end() && mpp1[s[i]]!=t[i]) || (mpp2.find(t[i])!=mpp2.end() && mpp2[t[i]]!=s[i]))
            {
                return 0;
            }
            mpp1[s[i]] = t[i];
            mpp2[t[i]] = s[i];;
        }
        return true;
    }
};
