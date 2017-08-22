// https://leetcode.com/problems/combination-sum-ii/#/description
// chi zhang, 2017-7-13

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> rs;
        vector<int> answer;
        Helper(candidates, 0, target, answer, 0, &rs);
        return rs;
    }
    
private:
    void Helper(vector<int>& candidates, int pos, int target, vector<int>& answer, int sum, vector<vector<int>>* rs) {
        if (sum == target) {
            rs->push_back(answer);
            return;
        }
        if (sum > target) {
            return;
        }
        if (pos == candidates.size()) {
            return;
        }
        
        answer.push_back(candidates[pos]);
        Helper(candidates, pos + 1, target, answer, sum + candidates[pos], rs);
        answer.pop_back();
        int i = 1;
        while (pos + i < candidates.size() && candidates[pos] == candidates[pos + i]) {
            ++i;
        }
        if (i > 1) {
            Helper(candidates, pos + i, target, answer, sum, rs);
            return;
        }
        Helper(candidates, pos + 1, target, answer, sum, rs);
    }
};
