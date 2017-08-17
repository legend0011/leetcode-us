// https://leetcode.com/problems/minimum-path-sum/description/
// chi zhang, 2017-8-16

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rs(m, vector<int>(n, 0));
        // Init
        rs[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rs[m - 1][i] = grid[m - 1][i] + rs[m - 1][i + 1];
        }
        for (int i = m - 2; i >= 0; --i) {
            rs[i][n - 1] = grid[i][n - 1] + rs[i + 1][n - 1];
        }
        
        // Calculate from bottom right to top left
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                rs[i][j] = grid[i][j] + min(rs[i][j + 1], rs[i + 1][j]);
            }
        }
        return rs[0][0];
        
    }
};
