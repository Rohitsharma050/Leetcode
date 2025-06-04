class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
        return word;
        string ans = "";
        int n = word.length();
        int maxPossibleLength = n-(numFriends-1);
        for(int i = 0;i<n;i++ )
        {
            string temp = word.substr(i,maxPossibleLength);
            ans = max(ans,temp);
        }
        
        return ans;

    }
};;
