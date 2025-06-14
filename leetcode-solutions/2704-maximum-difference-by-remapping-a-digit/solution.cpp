class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxNum = s;
        string minNum = s;

        // For maximum: replace first digit that's not '9' with '9'
        for (char c : s) {
            if (c != '9') {
                for (char &ch : maxNum) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // For minimum: replace first digit that's not '0' with '0'
        for (char c : s) {
            if (c != '0') {
                for (char &ch : minNum) {
                    if (ch == c) ch = '0';
                }
                break;
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};

