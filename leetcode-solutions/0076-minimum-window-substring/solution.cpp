class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int countrequired = t.length();
        map<char,int>mpp;
        if(t.length()>n)
        return "";
        for(char &ch: t)
        {
            mpp[ch]++;
        }
        int i=0; 
        int j = 0;
        int startIndex= 0;
        int windowSize = INT_MAX;
        while(j<n)
        {
            if(mpp[s[j]]>0)
            {
                countrequired--;
            }
            mpp[s[j]]--;
            while(countrequired==0)
            {   
                int currSize = j-i+1;
                if(currSize<windowSize)
                {
                    windowSize = currSize;
                    startIndex = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0)
                {
                    countrequired++;
                }
                
                i++;
            }
    j++;
        }
        return windowSize == INT_MAX?"":s.substr(startIndex,windowSize);
    }
};
