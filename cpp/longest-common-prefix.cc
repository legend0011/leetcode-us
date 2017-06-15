// https://leetcode.com/problems/longest-common-prefix/#/description
// chi zhang, 2017-6-15
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rs;
        // init
        int min_len = INT_MAX;
        for (const auto& str : strs) {
            int len = str.size();
            if (min_len > len) {
                rs = str;
                min_len = len;
            }
        }
        // get longest prefix
        bool found = false;
        while (!rs.empty()) {
            for (const auto& str : strs) {
                if (str.find(rs) != 0) {
                    rs = rs.substr(0, rs.size() - 1);
                    found = false;
                    break;
                }
                found = true;
            }
            if (found) {
                return rs;
            }
        }
        return rs;
    }
};
