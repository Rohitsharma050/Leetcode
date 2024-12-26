class Solution {
public:
    bool lemonadeChange(vector<int>& nums) {
        int five = 0, ten = 0;
        
        for (int bill : nums) {
            if (bill == 5) {
                // Accept the $5 bill
                five++;
            } else if (bill == 10) {
                // Check if we can give one $5 as change
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else { // bill == 20
                // Priority: Give one $10 and one $5, else give three $5 bills
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

