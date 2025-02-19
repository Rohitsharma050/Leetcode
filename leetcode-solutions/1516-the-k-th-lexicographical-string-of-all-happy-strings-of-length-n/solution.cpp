class Solution {
public:
    void generateHappyStrings(int n, string &curr, vector<string> &result) {
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                generateHappyStrings(n, curr, result);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> result;
        string curr;
        generateHappyStrings(n, curr, result);
        
        return k <= result.size() ? result[k - 1] : "";
    }
};

