// https://leetcode.com/problems/remove-element/#/description
// chi zhang, 2017-6-23
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t j = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                ++j;
            }
        }
        nums.resize(j);
        return j;
    }
};
