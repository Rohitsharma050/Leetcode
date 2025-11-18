class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {

        int n = bits.size();
        if(n==1)
        {
            return true;
        }

        int i = 0;
        while(i<n)
        {
            if(bits[i]==1)
            {
                i++;
            }
            i++;
            if(i==n-1 && bits[i]==0)
            {
                return true;
            }
        }
        return false;
        
    }
};
