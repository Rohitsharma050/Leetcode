class Solution {
public:
    bool canTransform(string s, string r) {
     int size = s.length();
     string s_clean, r_clean;
        for (char c : s) if (c != 'X') s_clean += c;
        for (char c : r) if (c != 'X') r_clean += c;
        if (s_clean != r_clean) return false;
        int  i =0;
        int j =0;
        //for L
        while(i<size && j<size)
        {
            while(i<size && s[i]!='L')
            {
                i++;
            }
            while(j<size && r[j]!='L')
            {
                j++;
            }
            if(i<size &&j<size)
            {
                if(i < j) 
                return false;
                i++;
                j++;
            }

        }
        //for R
         i =size-1;
         j =size-1;
        while(i>0 && j>0)
        {
            while(i>0 && s[i]!='R')
            {
                i--;
            }
            while(j>0 && r[j]!='R')
            {
                j--;
            }
            if(i>0 && j>0)
            {
                if(i > j) 
                return false;
                i--;
                j--;
            }

        }
        return true;
    }
};
