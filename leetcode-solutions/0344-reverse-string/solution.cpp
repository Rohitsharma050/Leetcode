class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        long len=s.size();
        int j=len-1;
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
    }
};
