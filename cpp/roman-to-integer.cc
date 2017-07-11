class Solution {
public:
    int romanToInt(string s) {
        //IVXLCDM
        unordered_map<char, int> mapping = {{'I', 1},{'V', 5},{'X', 10},{'L', 50}, {'C', 100},{'D', 500}, {'M', 1000}};
        int num = mapping[s.back()];
        for(int i = s.length() - 2; i >=0; --i) {
            if(mapping[s[i]] < mapping[s[i+1]]) {
                num -= mapping[s[i]];
            } else {
                 num += mapping[s[i]];
            }
        }
        
        return num;
    }
};

