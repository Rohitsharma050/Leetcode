class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while(s.length()>1)
        {
            int temp = 0;
            for(int i = 0;i<s.length();i++)
            {
                temp+=s[i]-'0';
            }
            s = to_string(temp);
        }
        return stoi(s);
    }
};
