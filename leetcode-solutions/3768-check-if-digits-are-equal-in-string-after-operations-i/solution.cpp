class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        while(s.length()>2)
            {
                string ans = "";
            for(int  i =0;i<s.length()-1;i++)
              {  int d1 = s[i]-'0';
                int d2 = s[i+1]-'0';
                int newd = (d1+d2)%10;
                ans+=to_string(newd);
               
              }
                 s = ans;
            }
         return (s.length() == 2 && s[0] == s[1]);  ;
    }
};
