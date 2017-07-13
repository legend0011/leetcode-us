// https://leetcode.com/problems/longest-common-prefix/
// fllin, 2017-7-12

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(auto inx = 0; strs.size() > 0; inx++) {
            for(auto i = 0; i < strs.size(); ++i) {
                if((inx >= strs[i].size()) || (i > 0 && strs[i][inx] != strs[i - 1][inx])){
                  return prefix;
                }             
            }
            prefix += strs[0][inx];
        }
        
        return prefix;
    }
};

