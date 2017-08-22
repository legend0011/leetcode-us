// https://leetcode.com/problems/next-permutation/#/description
// chi zhang, 2017-7-2

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first (left < right)
        int n = nums.size();
        if (n < 2) {
            return;
        }
        int left = -1, right = -1;
        bool found = false;
        for (left = n - 2, right = n - 1; left >= 0; --left, --right) {
            if (nums[left] < nums[right]) {
                found = true;
                break;
            }
        }
        if (!found) {
            // sort(nums.begin(), nums.end());
            reverse(nums.begin(), nums.end());
            return;
        }
        // swap (left, first larger than the left from the last)
        int first_larger_than_left_pos = -1;
        for (int i = n - 1; i > left; --i) {
            if (nums[i] > nums[left]) {
                first_larger_than_left_pos = i;
                break;
            }
        }
        swap(nums[left], nums[first_larger_than_left_pos]);
        // sort (right to end)
        // sort(nums.begin() + right, nums.end());
        reverse(nums.begin() + right, nums.end());
    }
};
