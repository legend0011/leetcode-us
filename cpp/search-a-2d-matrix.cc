// https://leetcode.com/problems/search-a-2d-matrix/description/
// chi zhang, 2017-8-22

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        
        int t = 0, b = m - 1;
        while (t <= b) {
            int mid = t + (b - t) / 2;
            if (target == matrix[mid][0]) {
                return true;
            }
            if (target < matrix[mid][0]) {
                b = mid - 1;
            } else {
                t = mid + 1;
            }
        }
        if (b < 0 || b >= m) {
            return false;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == matrix[b][mid]) {
                return true;
            }
            if (target < matrix[b][mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
