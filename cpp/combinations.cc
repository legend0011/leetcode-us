// https://leetcode.com/problems/combinations/description/
// chi zhang, 2017-8-23

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> rs;
        vector<int> now;
        Helper(now, 1, n, k, &rs);
        return rs;
    }
private:
    void Helper(vector<int>& now, int i, int n, int k, vector<vector<int>>* rs) {
        // PAY ATTENTION: 2 if order
        if (now.size() == k) {
            rs->push_back(now);
            return;
        }
        if (i > n) {
            return;
        }
        now.push_back(i);
        Helper(now, i + 1, n, k, rs);
        now.pop_back();
        Helper(now, i + 1, n, k, rs);
    }
};
