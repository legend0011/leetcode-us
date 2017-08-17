// https://leetcode.com/problems/unique-paths-ii/description/
// chi zhang, 2017-8-15

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > rs;
        if (obstacleGrid.empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // Init
        for (int i = 0; i < m; ++i) {
            rs.push_back(vector<int>(n, 0));
        }
        
        // Init first column
        bool is_reachable = true;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                is_reachable = false;
            }
            rs[i][0] = is_reachable ? 1 : 0;
        }
        // Init first row
        is_reachable = true;
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                is_reachable = false;
            }
            rs[0][j] = is_reachable ? 1 : 0;
        }
        
        // Calculate
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                rs[i][j] = obstacleGrid[i][j] == 1 ? 0 : rs[i - 1][j] + rs[i][j - 1];
            }
        }
        return rs[m - 1][n - 1];
    }
};
