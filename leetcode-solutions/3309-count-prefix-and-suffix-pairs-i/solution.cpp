class Solution {
public:
bool isPrefixAndSuffix(string str1,string str2)
{
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1>n2)
    return false;
    string prefix = str2.substr(0,n1);
    string suffix = str2.substr(n2-n1);
    if(str1==prefix && str1==suffix)
    return true;
    return false;

}
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        for(int i = 0;i<words.size();i++)
        {
            for(int j = i+1;j<words.size();j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]) )
                {   
                    count++;

                }
            }
        }
        return count;
    }
};
