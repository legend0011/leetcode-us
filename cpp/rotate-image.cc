// https://leetcode.com/problems/rotate-image/#/description
// chi zhang, 2017-7-18

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // in place
        int m = matrix.size();
        if (m == 0) {
            return;
        }
        int n = matrix[0].size();
        // Swap (i,j) <-> (j,i)
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (j < i) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        
        // Swap (i, j) (i, n - j - 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
