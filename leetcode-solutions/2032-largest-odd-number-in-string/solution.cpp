class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        if(n==0)
        return num;
        while(n!=0)
        {
            char lastchar=num[n-1];
            int lastdigit=lastchar-'0';
            if(lastdigit%2!=0)
            return num;
            else
            {
                num.pop_back();
                n--;
            }

        }
        return "";
    }
};
