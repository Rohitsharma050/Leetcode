class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";

    string result;

    // Handle negative numbers
    if ((numerator < 0) ^ (denominator < 0)) result += "-";

    // Use long long to avoid overflow
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    // Add integer part
    result += to_string(num / den);
    long long rem = num % den;
    if (rem == 0) return result;

    result += ".";

    // Map to store remainder positions
    unordered_map<long long, int> mp;
    while (rem != 0) {
        if (mp.count(rem)) {
            // repeating part found
            result.insert(mp[rem], "(");
            result += ")";
            break;
        }
        mp[rem] = result.size();
        rem *= 10;
        result += to_string(rem / den);
        rem %= den;
    }

    return result;
    }
};
