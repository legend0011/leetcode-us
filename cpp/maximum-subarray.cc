// https://leetcode.com/problems/maximum-subarray/#/description
// chi zhang, 2017-7-20

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        if (nums.empty()) {
            return max;
        }
        vector<int> dp;  // the best solution ends with i
        max = nums[0];
        dp.push_back(nums[0]);
        for (size_t i = 1; i < nums.size(); ++i) {
            int best = dp[i - 1] < 0 ? nums[i] : nums[i] + dp[i - 1];
            dp.push_back(best);
            max = best > max ? best : max;
        }
        return max;
    }
};
