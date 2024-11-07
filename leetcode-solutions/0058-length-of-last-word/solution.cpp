class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int i = 0;
        while(s[i]==' ' && i<s.length())
        {
            i++;
        }
        long j = i;
        long long len = 0;
        while(s[j]!=' ' && j<s.length())
        {
            len++;
            j++;
        }
        return len;
    }
};
