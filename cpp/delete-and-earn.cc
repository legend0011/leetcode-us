// https://leetcode.com/problems/delete-and-earn/description/
// chi zhang, 2018-2-9

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int length = 10001;
        vector<int> a(length, 0);
        for (int i = 0; i < nums.size(); ++i) {
            assert(nums[i] >= 1 && nums[i] <= 10000);
            a[nums[i]] += nums[i];
        }
        
        int f_2 = 0, f_1 = a[1];  // f_2 means f(i - 2)
        for (int i = 2; i < length; ++i) {
            int points_now = std::max(
                f_1,
                f_2 + a[i]
            );
            f_2 = f_1;
            f_1 = points_now;
        }
        return f_1;
    }
};
