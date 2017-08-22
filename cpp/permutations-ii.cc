// https://leetcode.com/problems/permutations-ii/#/description
// chi zhang, 2017-7-18

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Use next permutation
        sort(nums.begin(), nums.end());
        vector<vector<int>> rs;
        rs.push_back(nums);
        while (true) {
            int pos = NextPermutation(nums);
            if (pos == -1) {
                return rs;
            }
            rs.push_back(nums);
        }
    }
private:
    int NextPermutation(vector<int>& nums) {
        int pos = -1;
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                pos = i - 1;
                break;
            }
        }
        if (pos == -1) {
            return pos;
        }
        int swap_pos = -1;
        for (int i = nums.size() - 1; i > pos; --i) {
            if (nums[i] > nums[pos]) {
                swap_pos = i;
                break;
            }
        }
        swap(nums[pos], nums[swap_pos]);
        reverse(nums.begin() + pos + 1, nums.end());
        return pos;
    }
};
