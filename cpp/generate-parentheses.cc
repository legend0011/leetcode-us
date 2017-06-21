// https://leetcode.com/problems/generate-parentheses/#/description
// chi zhang, 2017-6-21

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rs;
        Helper("(", 1, 0, n, &rs);
        return rs;
    }
    void Helper(const string& str, int left_size, int right_size, int n, vector<string>* rs) {
        if (left_size == n && right_size == n) {
            rs->push_back(str);
            return;
        }
        if (left_size > n || right_size > n || right_size > left_size) {
            return;
        }
        Helper(str + "(", left_size + 1, right_size, n, rs);
        Helper(str + ")", left_size, right_size + 1, n, rs);
    }
};
