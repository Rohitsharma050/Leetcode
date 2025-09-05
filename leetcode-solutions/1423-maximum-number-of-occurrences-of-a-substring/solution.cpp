class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        unordered_map<char,int>uniqueChar;
        unordered_map<string,int>uniqueString;
        string temp = "";
        int i = 0,j = 0;
        while(j<n)
        {
            uniqueChar[s[j]]++;
            temp.push_back(s[j]);
            while(j-i+1>minSize || uniqueChar.size()>maxLetters)
            {
                uniqueChar[s[i]]--;
                if(uniqueChar[s[i]]==0)
                {
                    uniqueChar.erase(s[i]);
                }
                i++;
                temp.erase(temp.begin());
            }
            if((j-i+1>=minSize && j-i+1<=maxSize) && uniqueChar.size()<=maxLetters)
            {
                uniqueString[temp]++;
            }
            j++;
        }
        int ans =0;
        for(auto it:uniqueString)
        {
            ans = max(ans,it.second);
        }
        return ans;
    }
};
