// https://leetcode.com/problems/perfect-squares/description/
// chi zhang, 2018-2-21

class Solution {
public:
    int numSquares(int n) {
        // dp[i] indicate the result of given int, i
        // dp[i] = min(dp[i-1], dp[i-2*2], ..., dp[i-x*x]) + 1
        if (n <= 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            int min = INT_MAX;
            for (int x = 1; x*x <= i; ++x) {
                min = std::min(min, dp[i - x*x]);
            }
            dp[i] = min + 1;
        }
        return dp[n]; 
    }
};
