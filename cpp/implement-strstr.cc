// https://leetcode.com/problems/implement-strstr/#/description
// chi zhang, 2017-6-23
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t n = haystack.size(), m = needle.size();

        if (m == 0) {
            return 0;
        }

        for (size_t start = 0; start + m <= n; ++start) {
            size_t i = start;
            for (size_t j = 0; j < m; ++j) {
                if (haystack[i] == needle[j]) {
                    if (j == m - 1) {
                        return i - j;
                    }
                    ++i;
                } else {
                    break;
                }
            }
        }
        return -1;
    }
};
