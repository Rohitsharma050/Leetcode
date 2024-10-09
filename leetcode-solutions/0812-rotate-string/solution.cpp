class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        return false;
        string temp = s+s;
        for(int i =0;i<temp.size();i++)
        {
            string s1 = temp.substr(i,s.size());
            if(s1==goal)
            return true;

        }
        return false;
    }
};
