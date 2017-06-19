// https://leetcode.com/problems/letter-combinations-of-a-phone-number/#/description
// chi zhang, 2017-6-16
class Solution {
public:
    Solution() {
        digit2str_= {{'2', "abc"},
                     {'3', "def"},
                     {'4', "ghi"},
                     {'5', "jkl"},
                     {'6', "mno"},
                     {'7', "pqrs"},
                     {'8', "tuv"},
                     {'9', "wxyz"}};
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> rs({""});
        for (size_t i = 0; i < digits.size(); ++i) {
            char now = digits[i];
            if (digit2str_.find(now) == digit2str_.end()) {
                return vector<string>();
            }
            vector<string> tmp;
            for (size_t i = 0; i < rs.size(); ++i) {
                string base = rs[i];
                const string& posibilities = digit2str_[now];
                for (size_t i = 0; i < posibilities.size(); ++i) {
                    string str = base + posibilities[i];
                    tmp.push_back(str);
                }
            }
            rs.clear();
            rs = tmp;
        }
        return rs;
    }
private:
    unordered_map<char, string> digit2str_;
};
