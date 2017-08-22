// https://leetcode.com/problems/palindrome-number/#/description
// chi zhang, 2017-6-14
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        string str = to_string(x);
        for (int i = 0, j = str.size() - 1; i < j; ++i, --j) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
};
