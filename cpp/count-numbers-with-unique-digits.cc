// https://leetcode.com/problems/count-numbers-with-unique-digits/description/
// chi zhang, 2018-3-6

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        vector<int> rs(n+1, 0);
        rs[0] = 1;
        rs[1] = 10;
        for (int i = 2; i < n + 1; ++i) {
            rs[i] = (rs[i-1] - rs[i-2]) * (11 - i) + rs[i-1];
        }
        return rs[n];
    }
};
