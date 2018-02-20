// https://leetcode.com/problems/maximal-square/description/
// chi zhang, 2018-2-20

// O(n^2) space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        int max_side_length = 0;
        vector<vector<int>> cache(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    cache[i][j] = matrix[i][j] - '0';
                } else {
                    cache[i][j] = matrix[i][j] == '0' ?
                        0 : minOfThree(cache[i-1][j-1], cache[i-1][j], cache[i][j-1]) + 1;
                }
                max_side_length = std::max(cache[i][j], max_side_length);
            }
        }
        return max_side_length * max_side_length;
    }
private:
    int minOfThree(int a, int b, int c) {
        int tmp = std::min(a, b);
        return std::min(tmp, c);
    }
};

// O(n) space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        
        int max_side_length = 0;
        vector<int> cache(n, 0);
        int pre = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = cache[j];
                if (i == 0 || j == 0) {
                    cache[j] = matrix[i][j] - '0';
                } else {
                    cache[j] = matrix[i][j] == '0' ?
                        0 : minOfThree(pre, cache[j], cache[j-1]) + 1;
                }
                max_side_length = std::max(cache[j], max_side_length);
                pre = tmp;
            }
        }
        return max_side_length * max_side_length;
    }
private:
    int minOfThree(int a, int b, int c) {
        int tmp = std::min(a, b);
        return std::min(tmp, c);
    }
};
