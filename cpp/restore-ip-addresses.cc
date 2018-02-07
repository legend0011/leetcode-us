// https://leetcode.com/problems/restore-ip-addresses/description/
// chi zhang, 2017-10-30

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rs, now;
        Helper(s, 0, &now, &rs);
        return rs;
    }
private:
    void Helper(const string& s, int index, vector<string>* now, vector<string>* rs) {
        if (index == s.size() && now->size() == 4) {
            string now_str = JoinVector(*now, '.');
            rs->push_back(now_str);
            return;
        } else if (now->size() >= 4) {
            return;
        } else if (index >= s.size()) {
            return;
        }

        now->push_back(s.substr(index, 1));
        Helper(s, index + 1, now, rs);
        now->pop_back();
        
        if (s.substr(index, 1) == "0") {
            return;
        }
        now->push_back(s.substr(index, 2));
        Helper(s, index + 2, now, rs);
        now->pop_back();
    
        if (stoi(s.substr(index, 3)) <= 255) {
            now->push_back(s.substr(index, 3));
            Helper(s, index + 3, now, rs);
            now->pop_back();
        }   
    }
    string JoinVector(const vector<string>& vec, char sep) {
        string rs;
        for (const auto& str : vec) {
            rs.append(str);
            rs.append(string(1, sep));
        }
        rs.resize(rs.size() - 1);
        return rs;
    }
};
