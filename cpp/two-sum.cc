// https://leetcode.com/problems/two-sum/#/description
// chi zhang, 2017-6-8

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, size_t> num2pos;
        for (size_t i = 0; i < nums.size(); ++i) {
            num2pos[nums[i]] = i;
        }
        vector<int> rs;
        for (size_t i = 0; i < nums.size(); ++i) {
            int another = target - nums[i];
            if (num2pos.find(another) != num2pos.end() &&
                num2pos.at(another) != i) {
                    rs = {(int)i, (int)num2pos.at(another)};
                    return rs;
            }
        }
        return rs;
    }
};
