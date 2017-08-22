// https://leetcode.com/problems/unique-paths/description/
// chi zhang, 2017-8-15

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> rs;
        // Init
        for (int i = 0; i < m; ++i) {
            rs.push_back(vector<int>(n, 1));
        }
        // Calculate with DP
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                rs[i][j] = rs[i - 1][j] + rs[i][j - 1];
            }
        }
        return rs[m - 1][n - 1];
    }
};
