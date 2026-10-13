/*
 * Problem: Fraction to Recurring Decimal
 * Problem ID: 166
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.3 MB
 * Synced From: LeetCode
 * Date: 2026-10-13
 */


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans = "";

        if ((numerator < 0) != (denominator < 0))
            ans += "-";

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        ans += to_string(n / d);

        long long rem = n % d;

        if (rem == 0) return ans;

        ans += ".";

        unordered_map<long long, int> mp;

        while (rem != 0) {
            if (mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};
