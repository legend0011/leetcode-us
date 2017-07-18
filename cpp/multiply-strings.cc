// https://leetcode.com/problems/multiply-strings/#/description
// chi zhang, 2017-7-17

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<string> tmps;
        for (int i = num2.size() - 1; i >= 0; --i) {
            int single= num2[i] - '0';
            tmps.push_back(MultiplySingle(num1, single));
        }
        return Plus(tmps);
    }
    
private:
    bool Insert(string& rs, int single) {
        if (single >= 10) {
            return false;
        }
        rs.insert(rs.begin(), 1, single + '0');
        return true;
    }
    
    string Add2Nums(string& n1, string& n2) {
        string rs;
        if (n1.size() > n2.size()) {
            n2.insert(n2.begin(), n1.size() - n2.size(), '0');
        } else {
          n1.insert(n1.begin(), n2.size() - n1.size(), '0');
        }
        int carry = 0;
        for (int i = n1.size() - 1; i >= 0; --i) {
            int nowi = n1[i] - '0';
            int nowj = n2[i] - '0';
            int now = nowi + nowj + carry;
            carry = now / 10;
            Insert(rs, now % 10);
        }
        if (carry > 0) {
            Insert(rs, carry);
        }
        return rs;
    }
    
    string Plus(const vector<string>& tmps) {
        string rs = "0";
        for (size_t i = 0; i < tmps.size(); ++i) {
            string tmp = tmps[i];
            tmp.insert(tmp.end(), i, '0');
            rs = Add2Nums(tmp, rs);
        }
        return rs;
    }

    string MultiplySingle(string num1, int single) {
        if (single == 0) {
            return "0";
        }
        string rs;
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; --i) {
            int now = num1[i] - '0';
            int multi = now * single + carry;
            carry = multi / 10;
            Insert(rs, multi % 10);
        }
        if (carry > 0) {
            Insert(rs, carry);
        }
        return rs;
    }
};
