// https://leetcode.com/problems/4sum/#/description
// chi zhang, 2017-6-15
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rs;
        for (size_t i = 0; i + 3 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (size_t j = i + 1; j + 2 < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                size_t l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (l > j + 1 && nums[l] == nums[l - 1]) {
                        ++l;
                        continue;
                    }
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        rs.push_back(vector<int>({nums[i], nums[j], nums[l], nums[r]}));
                        ++l;
                    } else if (sum < target) {
                        ++l;
                    } else {
                        --r;
                    }
                }
            }
        }
        return rs;
    }
};
