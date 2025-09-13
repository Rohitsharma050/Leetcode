class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    {
        return true;
    }
    return false;
}
    int maxFreqSum(string s) {
        int n = s.length();
        int vowelFreq = 0;
        int consFreq = 0;
        unordered_map<char ,int>freq;
        for(int i = 0;i<n;i++)
        {
            freq[s[i]]++;
        }
        for(auto it:freq)
        {
            if(isVowel(it.first))
            {
                vowelFreq = max(it.second,vowelFreq);
            }
            else
            {
                consFreq = max(it.second,consFreq);
            }
        }
        return vowelFreq+consFreq;
    }
};
