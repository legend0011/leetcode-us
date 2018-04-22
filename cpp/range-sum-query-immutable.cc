// https://leetcode.com/problems/range-sum-query-immutable/description/
// chzhang, 2018-2-22

class NumArray {
public:
    NumArray(vector<int> nums) : cache_(nums.size() + 1, 0) {
        for (int i = 1; i < nums.size() + 1; ++i) {
            cache_[i] = cache_[i-1] + nums[i-1];
            cout << cache_[i] << endl;
        }
    }
    
    int sumRange(int i, int j) {
        if (i <= j && i >= 0) {
            return cache_[j+1] - cache_[i];
        }
        return 0;
    }
private:
    vector<int> cache_;  // n + 1, cache_[i]represents the sum of [0, i), rs = cache[j+1] - cache[i]
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
