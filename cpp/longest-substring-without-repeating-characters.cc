// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
// chi zhang, 2017-6-9

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, size_t> c2p;
        size_t max = 0;
        for (size_t i = 0; i < s.size();) {
            char now = s[i];
            if (c2p.find(now) == c2p.end()) {
                c2p[now] = i;
                ++i;
            } else {
                size_t pos = c2p.at(now);
                i = pos + 1;
                c2p.clear();
            }
            max = c2p.size() > max ? c2p.size() : max;
        }
        return max;
    }
};
