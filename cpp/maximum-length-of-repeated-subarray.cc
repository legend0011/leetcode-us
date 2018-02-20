// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
// chi zhang, 2018-2-18

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        // cache[i,j] represents result of A[0:i], B[0:j]
        vector<vector<int>> cache(m, vector<int>(n, 0));
        
        int rs = 0;
        if (m > 0 && n > 0) {
            cache[0][0] = (A[0] == B[0]) ? 1 : 0;
        } else {
            return rs;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i] == B[j]) {
                    if (i > 0 && j > 0) {
                        cache[i][j] = cache[i-1][j-1] + 1;
                    } else {
                        cache[i][j] = 1;
                    }
                    rs = std::max(rs, cache[i][j]);
                }
            }
        }
        return rs;
    }
};
