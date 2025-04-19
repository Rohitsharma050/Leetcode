// //memoization
// class Solution {
// public:
//     int n; // To store the number of stairs (size of cost array)

//     // A recursive function to calculate the minimum cost from step 'i' to the top
//     int solve(int i, vector<int>& dp, vector<int>& cost)
//     {
//         // Base case: if we are at or beyond the last step, cost is 0 (no more steps to take)
//         if(i >= n)
//         {
//             return 0;
//         }

//         // If we have already computed the result for step i, return it (memoization)
//         if(dp[i] != -1)
//             return dp[i];

//         // Option 1: Take one step from current i and add the cost
//         int take = cost[i] + solve(i + 1, dp, cost);

//         // Option 2: Skip one step and take two steps from current i
//         int nottake = cost[i] + solve(i + 2, dp, cost);

//         // Store and return the minimum cost between the two options
//         return dp[i] = min(take, nottake);
//     }

//     // Main function to calculate the minimum cost to climb to the top of the stairs
//     int minCostClimbingStairs(vector<int>& cost) {
//         n = cost.size(); // Initialize n with the number of steps

//         // Create DP arrays to memoize results for two starting points (step 0 and step 1)
//         vector<int> dp1(n + 1, -1);

//         // We can start at either step 0 or step 1, return the minimum of both options
//         return min(solve(0, dp1, cost), solve(1, dp1, cost));
//     }
// };


//tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n  = cost.size();
       int first = cost[1];
       int second = cost[0];
       for(int i = 2;i<n;i++)
       {
            int temp = first;
            first = cost[i] + min(first,second);
            second = temp;

       }
       return min(first,second);
    }
};
