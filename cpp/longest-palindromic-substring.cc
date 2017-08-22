// https://leetcode.com/problems/longest-palindromic-substring/#/description
// chi zhang
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rs;
        for (int m = 0; m < n; ++m) {
            // even palindrome 1
            for (int l = m, r = m + 1; l >= 0 && r < n; --l, ++r) {
                if (s[l] == s[r]) {
                    if (rs.size() < r - l + 1) {
                        rs.assign(s.begin() + l, s.begin() + r + 1);
                    }
                } else {
                    break;
                }
            }
            
            // odd palindrome
            for (int l = m, r = m; l >=0 && r < n; --l, ++r) {
                if (s[l] == s[r]) {
                    if (rs.size() < r - l + 1) {
                        rs.assign(s.begin() + l, s.begin() + r + 1);
                    }
                } else {
                    break;
                }
            }
        }
        return rs;
    }
};
