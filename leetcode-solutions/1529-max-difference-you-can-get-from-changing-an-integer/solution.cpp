class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxNum = s;
        string minNum = s;

        // Replace first non-'9' digit in maxNum with '9'
        for (char c : s) {
            if (c != '9') {
                for (char &ch : maxNum) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // Replace first digit (not '1') with '1' in minNum, but make sure we don't make the first digit '0'
        if (s[0] != '1') {
            char toReplace = s[0];
            for (char &ch : minNum) {
                if (ch == toReplace) ch = '1';
            }
        } else {
            // If first digit is '1', replace next non-'0' digit with '0'
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char toReplace = s[i];
                    for (char &ch : minNum) {
                        if (ch == toReplace) ch = '0';
                    }
                    break;
                }
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};

