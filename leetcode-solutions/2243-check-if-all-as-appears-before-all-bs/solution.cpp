class Solution {
public:
    bool checkString(string s) {
        bool isb = false;
        for (int i = 0; i < s.length(); i++) {   
            if (s[i] == 'b')
                isb = true;
            if (s[i] == 'a' && isb == true)
                return false;
        }
        return true;
    }
};

