class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='a' || ch=='e' ||  ch=='i' ||  ch=='o' ||  ch=='u' ||  ch=='A' ||    ch=='E' ||  ch=='I' ||  ch=='O' ||  ch=='U'  )
    return true;
    return false;
}
    bool doesAliceWin(string s) {
        int n = s.length();
        int vowel = 0;
        for(int i = 0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                vowel++;
            }
        }
        if(vowel==0)
        return false;
        return true;
    }
};
