class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxfreq(26,0);
        vector<string>ans;
        for(auto word:words2)
        {
                vector<int>freq(26,0);
            for(auto ch:word)
            {
                freq[ch-'a']++;
            }
            for(int i = 0;i<26;i++)
            {
                maxfreq[i]=max(maxfreq[i],freq[i]);
            }

        }
        for(auto word:words1)
        {
            bool flag = true;
            vector<int>freq(26,0);
            for(auto ch:word)
            {
                freq[ch-'a']++;
            }
            for(int i = 0;i<26;i++)
            {
                if(freq[i]<maxfreq[i])
                {
                    flag =false;
                    break;
                }
            }
            if(flag)
            ans.push_back(word);
        }
        return ans;
    }
};
