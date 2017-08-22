// https://leetcode.com/problems/combination-sum/#/description
// chi zhang, 2017-7-11

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> rs;
        vector<int> now;
        Helper(candidates, 0, target, now, 0, &rs);
        return rs;
    }
private:
    void Helper(const vector<int>& nums, int pos, int target, vector<int>& now, int sum, vector<vector<int>>* rs) {
        if (sum == target) {
            rs->push_back(now);
            return;
        }
        if (sum > target || pos == nums.size()) {
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            now.push_back(nums[i]);
            Helper(nums, i, target, now, sum + nums[i], rs);
            now.pop_back();
        }
    }
};
