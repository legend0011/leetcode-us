// https://leetcode.com/problems/coin-change/description/
// chi zhang, 2018-3-2

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        vector<int> count(amount+1, -1);  // count[i] is the fewest number of coins of amount 'i'
        count[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            int rs = INT_MAX;
            for (int coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                if (count[i-coin] == -1) {
                    continue;
                }
                rs = min(rs, count[i-coin] + 1);
            }
            count[i] = rs == INT_MAX ? -1 : rs;
        }
        return count[amount];
    }
};
