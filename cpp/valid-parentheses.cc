// https://leetcode.com/problems/valid-parentheses/#/description
// chi zhang, 2017-6-19
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (const auto& c : s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }
            if (Match(c, st.top())) {
                st.pop();
                continue;
            } else {
                st.push(c);
                continue;
            }
        }
        return st.empty();
    }
private:
    bool Match(char c1, char c2) {
        switch (c1) {
            case ']' : {
                return c2 == '[';
            }
            case ')' : {
                return c2 == '(';
            }
            case '}' : {
                return c2 == '{'; 
            }
            default : return false;
        }
    }
};
