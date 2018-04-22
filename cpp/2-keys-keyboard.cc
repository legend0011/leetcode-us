// https://leetcode.com/problems/2-keys-keyboard/description/
// chi zhang, 2018-3-7

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        if (n == 0) {
            return 0;
        }
        dp[1] = 0;
        for (int i = 2; i < n + 1; ++i) {
            int tmp = i;
            for (int b = 2; b < i; ++b) {
                if (i % b == 0) {
                    tmp = std::min(dp[i / b] + b, tmp);
                }
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};
