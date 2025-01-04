class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char>uniqueLetters;
        vector<pair<int,int>>letters(26,{-1,-1});
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            int index = ch -'a';
            if(letters[index].first==-1)
            {
                letters[index].first = i;
            }
            letters[index].second = i;
        }

        int result = 0;
        for(int i = 0;i<26;i++)
        {
            int firstIndex = letters[i].first;
            int lastIndex  = letters[i].second;
            if(firstIndex==-1)
            continue;
            unordered_set<char>middleLetters;
            for(int k = firstIndex+1;k<lastIndex;k++)
            {
                middleLetters.insert(s[k]);
            }
            result+=middleLetters.size();
        }
        return result;
    }
};
