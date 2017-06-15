// https://leetcode.com/problems/3sum/#/description
// chi zhang, 2017-6-15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nlogn + n^2
        vector<vector<int>> rs;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 夹逼法
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    ++l;
                    continue;
                }
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    vector<int> tmp({nums[i], nums[l], nums[r]});
                    rs.push_back(tmp);
                    ++l;
                } else if (sum < 0) {
                    ++l;
                } else {
                    --r;
                }
            }
        }
        return rs;
    }
};
