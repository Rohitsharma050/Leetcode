class Solution {
public:
    bool isBalanced(string num) {
        int oddSum = 0;
        int evenSum = 0;
        int n = num.length();
        for(int i = 0;i<n;i++)
        {
            int number = num[i]-'0';
            if(i%2==0)
            {
                evenSum+=number;
            }
            else
            {
                oddSum+=number;
            }
        }
       return evenSum==oddSum;

    }
};
