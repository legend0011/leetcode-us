// https://leetcode.com/problems/search-for-a-range/#/description
// chi zhang, 2017-7-4

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> rs({-1, -1});
        // left bound
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target <= nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l < 0 || l >= n) {
            return rs;
        }
        if (nums[l] != target) {
            return rs;
        }
        rs[0] = l;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target >= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        rs[1] = r;
        return rs;
    }
};
