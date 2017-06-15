// https://leetcode.com/problems/3sum-closest/#/description
// chi zhang, 2017-6-15
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // nlogn + n^2
        sort(nums.begin(), nums.end());
        int min_gap = INT_MAX;
        int rs = INT_MAX;
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            size_t l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < min_gap) {
                    min_gap = abs(sum - target);
                    rs = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return rs;
    }
};
