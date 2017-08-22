// https://leetcode.com/problems/string-to-integer-atoi/#/description
// chi zhang, 2017-6-14
class Solution {
public:
    int myAtoi(string str) {
        // remove heading and tailing space
        Trim(str);
        if (str.empty()) {
            return 0;
        }
        bool is_neg = false;
        if (str[0] == '-' || str[0] == '+') {
            if (str[0] == '-') {
                is_neg = true;
            }
            str = str.substr(1);
        }
        int rs = 0;
        for (int i = 0; i < str.size(); ++i) {
            int num = str[i] - '0';
            if (num < 0 || num > 9) {
                break;
            }
            if (is_neg) {
                if (rs < (INT_MIN + num) / 10) {
                    return INT_MIN;
                }
                rs = rs * 10 - num;
            } else {
                if (rs > (INT_MAX - num) / 10) {
                    return INT_MAX;
                }
                rs = rs * 10 + num;
            }
            
        }
        return rs;
    }
private:
    void Trim(string& origin) {
        int i = 0;
        while (i < origin.size() && origin[i] == ' ') {
            ++i;
        }
        origin.erase(0, i);  // i not included
        int j = origin.size() - 1;
        while (j >= 0 && origin[j] == ' ') {
            --j;
        }
        origin.erase(j + 1, origin.size());
    }
};
