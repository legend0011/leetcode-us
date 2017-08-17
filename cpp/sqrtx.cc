// https://leetcode.com/problems/sqrtx/submissions/1/
// chi zhang, 2017-8-17

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int l = 0, r = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int target = x / mid;
            if (mid == target) {
                return mid;
            } else if (mid > target) {
                r = mid - 1;
            } else if (mid < target) {
                l = mid + 1;
            }
        }
        return r;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        // newton
        assert(x >= 0);
        if (x == 0) {
            return 0;
        }
        /*
        int a = x;
        while (a > x / a) {
            a = a / 2 + x / 2 / a;
        }
        return a;*/
        long a = x;
        while (a * a > x) {
            a = (a*a + x) / 2 / a;
        }
        return a;
    }
};
