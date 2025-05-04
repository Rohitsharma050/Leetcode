class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int len = s.length();
        int prod = 0;
        for(int i = 0;i<len;i++)
            {
                for(int j = i+1;j<len;j++)
                    {
                        int temp =(s[i]-'0')*(s[j]-'0');
                        prod = max(prod,temp);
                    }
            }
        return prod;
    }
};
