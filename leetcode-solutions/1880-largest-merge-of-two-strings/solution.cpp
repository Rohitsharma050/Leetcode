class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        int n1 = word1.length(), n2 = word2.length();
        string ans = "";
        
        while (i < n1 && j < n2) {
            if (word1.substr(i) > word2.substr(j)) {
                ans += word1[i++];
            } else {
                ans += word2[j++];
            }
        }
        
        while (i < n1) {
            ans += word1[i++];
        }
        
        while (j < n2) {
            ans += word2[j++];
        }
        
        return ans;
    }
};

