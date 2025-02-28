class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
    
    // Step 1: Compute LCS using DP
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    // Step 2: Construct SCS using the LCS table
    int i = m, j = n;
    string scs = "";
    
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            scs += str1[i - 1]; 
            i--; j--;  // Move diagonally in LCS table
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            scs += str1[i - 1]; 
            i--;  // Move up
        } 
        else {
            scs += str2[j - 1]; 
            j--;  // Move left
        }
    }

    // Add remaining characters from str1 and str2
    while (i > 0) { scs += str1[i - 1]; i--; }
    while (j > 0) { scs += str2[j - 1]; j--; }

    // Reverse the string since we built it backwards
    reverse(scs.begin(), scs.end());
    return scs;
    }
};
