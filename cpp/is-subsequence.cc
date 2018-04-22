// https://leetcode.com/problems/is-subsequence/description/
// chi zhang, 2018-3-6

// common method: s(m), t(n), time: O(n);
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size(); ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == s.size();
    }
};

// Follow up: a lot of s, comparing to one t: less than O(n), binary search for a target bigger than i

class Solution {
public:
    Solution(const string& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (char2indexes.find(s[i]) == char2indexes.end()) {
                char2indexes[s[i]] = vector<int>();
            }
            char2indexes[s[i]].push_back(i);
        }
        t = s;
    }
    
    bool isSubsequence(string s) {
        int j = -1;
        for (char c : s) {
            if (char2indexes.find(c) == char2indexes.end()) {
                return false;
            }
            j = binarySearchBiggerThanJ(char2indexes[c], j);
            if (j > t.size() - 1) {
                return false;
            }
        }
        return true;
    }
private:
    map<char, vector<int>> char2indexes;
    string t;
    
    int binarySearchBiggerThanJ(vector<int> v, int target) {
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target >= v[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

int main() {
    string s = "acg";
    string t = "abcdg";
    Solution sol(t);
    cout << sol.isSubsequence(s);
    return 0;
}
