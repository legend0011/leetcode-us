// https://leetcode.com/problems/powx-n/#/description
// chi zhang, 2017-7-19

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            if (n == INT_MIN) {
                return 1.0 / (myPow(x, INT_MAX) * x);
            }
            return 1.0 / myPow(x, -n);
        }
        double rs = 1.0;
        double item = x;
        for (int i = 0; (n >> i) > 0 ; ++i) {
            int binary = (n >> i) & 1;
            if (binary == 1) {
                rs *= item;
            }
            item *= item;
        }
        return rs;
    }
};
