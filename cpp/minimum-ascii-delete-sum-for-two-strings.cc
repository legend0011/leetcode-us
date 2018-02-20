// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
// chi zhang, 2018-2-19

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        for (int i = 1; i <= n; ++i) {
            dp[0][i] = dp[0][i-1] + s2[i-1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = minOfThree(
                    dp[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : s1[i-1] + s2[j-1]),
                    dp[i-1][j] + s1[i-1],
                    dp[i][j-1] + s2[j-1]
                );
            }
        }
        return dp[m][n];
    }
private:
    int minOfThree(int a, int b, int c) {
        int min = a < b ? a : b;
        return min < c ? min : c;
    }
};
