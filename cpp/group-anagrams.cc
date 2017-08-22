// https://leetcode.com/problems/group-anagrams/#/description
// chi zhang, 2017-7-19

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rs;
        map<string, vector<string>> sorted2group;
        for (const auto& str : strs) {
            vector<char> tmp;
            for (size_t j = 0; j < str.size(); ++j) {
                tmp.push_back(str[j]);
            }
            sort(tmp.begin(), tmp.end());
            string sorted;
            for (size_t j = 0; j < tmp.size(); ++j) {
                sorted.append(1, tmp[j]);
            }
            if (sorted2group.find(sorted) == sorted2group.end()) {
                sorted2group.insert(make_pair(sorted, vector<string>()));
            }
            sorted2group[sorted].push_back(str);
        }
        for (const auto& it : sorted2group) {
            rs.push_back(it.second);
        }
        return rs;
    }
};
