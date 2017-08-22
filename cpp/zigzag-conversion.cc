// https://leetcode.com/problems/zigzag-conversion/#/description
// chi zhang, 2017-6-12
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;
    vector<string> table(numRows, "");
    for (int i = 0; i < s.size(); ++i) {
        int tmp = i % (numRows * 2 - 2);
        int j;
        if (tmp < numRows) {
            j = tmp;
        } else {
            j = 2 * numRows - tmp - 2;
        }
        table[j] += s[i];
    } 
    string rs;
    for (int i = 0; i < numRows; ++i) {
        rs.append(table[i]);
    }
    return rs;
  }
};
