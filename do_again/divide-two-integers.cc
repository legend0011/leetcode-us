// https://leetcode.com/problems/divide-two-integers/#/description

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        if (dividend < 0 && divisor < 0) {
            return divide(-dividend, -divisor);
        } else if (dividend < 0 && divisor > 0) {
            if (dividend == INT_MIN && divisor == 1) {
                return INT_MAX;
            }
            return -divide(-dividend, divisor);
        } else if (dividend > 0 && divisor < 0) {
            return -divide(dividend, -divisor);
        }
        int sum = 0;
        int rs = 0;
        int left = dividend - sum;
        while (left >= divisor) {
            int multi = divisor;
            int rs_sum = 0;
            while (left - multi >= 0) {
                multi <<= 1;
                ++rs_sum;
            }
            sum += divisor << (rs_sum - 1);
            rs += 2 << (rs_sum - 1);
            left = dividend - sum;
        }
        return rs >> 1;
    }
};
