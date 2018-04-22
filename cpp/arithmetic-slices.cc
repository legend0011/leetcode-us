// https://leetcode.com/problems/arithmetic-slices/description/
// chi zhang, 2018-3-7

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> tmp;
        for (int i = 1; i < n; ++i) {
            tmp.push_back(A[i] - A[i-1]);
        }
        if (tmp.size() > 0) {
            tmp.push_back(tmp[tmp.size() - 1] + 1);
        }
        
        
        int len = 2;
        int rs = 0;
        int max = 0;
        
        cout << endl;
        for (int i = 1; i < tmp.size(); ++i) {
            if (tmp[i] == tmp[i - 1]) {
                ++len;
                if (len >= 3) {
                    max = std::max(max, (len-2) * (len - 1) / 2);
                }
            } else {
                if (len >= 3) {
                    cout << "len:" << len << endl;
                    cout << "max:" << max << endl;
                    rs += max;
                }
                len = 2;
                max = 0;
            }
        }
        
        return rs;
    }
};
