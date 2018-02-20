// https://leetcode.com/problems/ugly-number-ii/description/
// chi zhang, 2018-2-20

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) {
            return 0;
        }
        vector<int> uglys(n);
        uglys[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        
        for (int i = 1; i < n; ++i) {
            uglys[i] = minOfThree(uglys[index2] * 2, uglys[index3] * 3, uglys[index5] * 5);
            
            if (uglys[i] == uglys[index2] * 2) {
                ++index2;
            } else if (uglys[i] == uglys[index3] * 3) {
                ++index3;
            } else {
                ++index5;
            }
            
            if (uglys[i] == uglys[i-1]) {
                --i;
            }
        }
        return uglys[n-1];
    }
private:
    int minOfThree(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }
};
