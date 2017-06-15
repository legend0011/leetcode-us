// https://leetcode.com/problems/3sum/#/description
// chi zhang, 2017-6-15
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nlogn + n^2logn
        vector<vector<int>> rs;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // dedup, 只看第一次出现的
            for (size_t j = i + 1; j + 1 < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // dedup
                int target = -(nums[i] + nums[j]);
                int pos = FindNum(nums, j + 1, target);
                if (pos > 0) {
                    vector<int> tmp({nums[i], nums[j], nums[pos]});
                    rs.push_back(tmp);
                }
            }
        }
        return rs;
    }
private:
    int FindNum(const vector<int>& nums, int start, int target) {
        int l = start, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
