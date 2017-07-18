// https://leetcode.com/problems/count-and-say/#/description
// chi zhang, 2017-7-11

class Solution {
public:
    string countAndSay(int n) {
        if (n < 0) {
            return "";
        }
        string rs = "1";
        for (int i = 1; i < n; ++i) {
            rs = Generate(rs);
        }
        return rs;
    }
private:
    string Generate(const string& num) {
        string rs;
        string tmp(num + "#");
        int count = 1, say = tmp[0] - '0';
        for (size_t i = 0, j = 1; j < tmp.size(); ++i, ++j) {
            if (tmp[i] == tmp[j]) {
                ++count;
            } else {
                rs = rs + std::to_string(count) + std::to_string(say);
                count = 1;
                say = tmp[j] - '0';
            }
        }
        return rs;
    }
};
