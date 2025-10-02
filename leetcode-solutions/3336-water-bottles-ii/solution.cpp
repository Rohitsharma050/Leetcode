class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;
        while(numBottles>0)
        {
            emptyBottles += numBottles;
            totalDrunk += numBottles;
            int newBottles = 0;
            while(emptyBottles>=numExchange)
            {
                emptyBottles-=numExchange;
                newBottles++;
                numExchange++;
            }
            numBottles = newBottles;
            
        }
        return totalDrunk;
    }
};
