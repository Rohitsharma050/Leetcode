class Solution {
public:
    string vowelPattern(const string &word) {
        string res;
        for (char c : word) {
            char ch = tolower(c);
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') res.push_back('*');
            else res.push_back(ch);
        }
        return res;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> lowerMap, vowelMap;
        for (auto &w : wordlist) {
            string lower;
            for (char c : w) lower.push_back(tolower(c));
            if (!lowerMap.count(lower)) lowerMap[lower] = w;
            string pattern = vowelPattern(w);
            if (!vowelMap.count(pattern)) vowelMap[pattern] = w;
        }
        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) ans.push_back(q);
            else {
                string lower;
                for (char c : q) lower.push_back(tolower(c));
                if (lowerMap.count(lower)) ans.push_back(lowerMap[lower]);
                else {
                    string pattern = vowelPattern(q);
                    if (vowelMap.count(pattern)) ans.push_back(vowelMap[pattern]);
                    else ans.push_back("");
                }
            }
        }
        return ans;
    }
};

