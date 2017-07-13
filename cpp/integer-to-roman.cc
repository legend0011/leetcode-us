// https://leetcode.com/problems/integer-to-roman
// fllin, 2017-7-11

class Solution {
public:
    string intToRoman(int num) {
         //IVXLCDM
        // Bit
        string bit[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        // Ten
        string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX" , "LXXX", "XC"};
        // Hundred
        string hundred[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC" , "CM"};
        //Thousand
        string thousand[] = {"", "M", "MM", "MMM", "MMMM"};
        
        return thousand[num / 1000] + hundred[(num % 1000) / 100] + ten[(num % 100) / 10] + bit[num % 10];
    }
};

