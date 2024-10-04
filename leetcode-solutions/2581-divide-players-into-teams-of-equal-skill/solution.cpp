class Solution {
public:
        long long dividePlayers(vector<int>& skill) {
    // Step 1: Sort the array
    sort(skill.begin(), skill.end());
    
    int n = skill.size();
    long long total_chemistry = 0;
    
    // Step 2: Calculate the target sum of the first and last player's skills
    int target_sum = skill[0] + skill[n - 1];
    
    // Step 3: Two-pointer approach to check pairs
    for (int i = 0; i < n / 2; i++) {
        // Check if the sum of current pair matches the target sum
        if (skill[i] + skill[n - 1 - i] != target_sum) {
            return -1;  // If a pair does not match the target, return -1
        }
        // Add the product of the pair to the total chemistry
        total_chemistry += (long long)skill[i] * skill[n - 1 - i];
    }
    
    return total_chemistry;
    }
};
