// https://leetcode.com/problems/length-of-last-word/#/description
// chi zhang, 2017-7-26

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int start;
        for (start = s.size() - 1; start >= 0; --start) {
            if (s[start] != ' ') {
                break;
            }
        }
        for (int i = start; i >= 0; --i) {
            if (s[i] != ' ') {
                ++len;
            } else {
                break;
            }
        }
        return len;
    }
};
