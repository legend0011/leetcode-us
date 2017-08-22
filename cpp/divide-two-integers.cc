// https://leetcode.com/problems/divide-two-integers/#/description 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 ||
            (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        bool is_neg = false;
        if ((dividend < 0 && divisor > 0) ||
             (dividend > 0 && divisor < 0)) {
            is_neg = true;     
        }
        long long sum = 0;
        long long rs = 0;
        while (dvd >= dvs) {
            long long tmp = dvs, multiple = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                multiple <<= 1;
            }
            rs += multiple;
            dvd -= tmp;
        }
        return (is_neg ? -rs : rs);
    }
};
