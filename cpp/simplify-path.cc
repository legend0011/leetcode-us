// https://leetcode.com/problems/simplify-path/description/
// chi zhang, 2017-8-21

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> pieces;
        Split(path, "/", &pieces);
        int i = 0;
        vector<string> rs;
        for (const auto& piece : pieces) {
            if (piece == ".") {
                continue;
            } else if (piece == "..") {
                if (!rs.empty()) {
                    rs.pop_back();
                } else {
                    continue;  // /a/../../.. returns /
                }             
            } else {
                rs.push_back(piece);
            }
        }
        if (rs.empty()) {
            return "/";
        }
        string result;
        Join(rs, "/", &result);
        return result;
    }
private:
    void Split(const string& str, const string& sep, vector<string>* rs) {
        int start = 0;
        while (start < str.size()) {
            size_t found = str.find(sep, start);
            if (found == string::npos) {
                rs->push_back(str.substr(start));
                return;
            }
            string piece = str.substr(start, found - start);
            if (!piece.empty()) {
                rs->push_back(piece);
                start = start + found - start;
            } else {
                ++start;
            }
        }
    }
    void Join(const vector<string>& strs, const string& sep, string* rs) {
        for (const auto& str : strs) {
            rs->append(sep).append(str);
        }
    }
};
