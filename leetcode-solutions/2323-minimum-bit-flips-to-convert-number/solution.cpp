class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorAns = start ^ goal;
        int size = sizeof(int)*  8;
        int count = 0;
        for(int i=0;i<size;i++)
        {
            if((xorAns>>i) & 1)
            {
                count++;
            }
        }
        return count;

    }
};
