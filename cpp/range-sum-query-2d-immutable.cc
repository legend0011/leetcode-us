// https://leetcode.com/problems/range-sum-query-2d-immutable/description/
// chi zhang, 2018-2-22

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) : m_(matrix.size()) {
        if (matrix.empty()) {
            return;
        }
        n_ = matrix[0].size();
        for (int i = 0; i < m_ + 1; ++i) {
            cache_.push_back(vector<int>(n_ + 1, 0));
        }
        
        for (int i = 1; i < m_ + 1; ++i) {
            for (int j = 1; j < n_ + 1; ++j) {
                cache_[i][j] = cache_[i-1][j] + cache_[i][j-1] -cache_[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        for (int i = 1; i < m_ + 1; ++i) {
            for (int j = 1; j < n_+1; ++j) {
                cout << cache_[i][j] << ",";
            }
            cout << endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 <= row2 && col1 <= col2 &&
            row1 >= 0 && row2 >= 0 &&
            row2 < m_ && col2 < n_) {
            return cache_[row2+1][col2+1] - cache_[row2+1][col1] - cache_[row1][col2+1] + cache_[row1][col1] ;
        }
        return 0;
    }
private:
    int m_;
    int n_;
    vector<vector<int>> cache_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
