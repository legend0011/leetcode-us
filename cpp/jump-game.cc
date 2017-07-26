// https://leetcode.com/problems/jump-game/#/description
// chi zhang, 2017-7-23

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = 1;
        int i = 0;
        for (i = 0; i < nums.size() - 1; ++i) {
            int now = max(last - 1, nums[i]);
            if (now == 0) {
                return false;
            }
            last = now;
        }
        return true;
    }
};
