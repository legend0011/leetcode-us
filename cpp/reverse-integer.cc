class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) {
            return 0;
        }
        if (x < 0) {
            return -reverse(-x);
        }
        if (x == 0) {
            return 0;
        }
        int rs = 0;
        while (x > 0) {
            if (rs > (INT_MAX - x % 10) / 10) {
                return 0;
            }
            rs = rs * 10 + (x % 10);
            x /= 10;
        }
        return rs;
    }
};
