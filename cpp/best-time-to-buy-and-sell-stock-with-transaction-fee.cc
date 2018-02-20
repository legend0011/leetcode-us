// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// chi zhang, 2018-2-18

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.empty()) {
            return 0;
        }
        int soldp = INT_MIN + 50001, buyp = -prices[0], holdp = INT_MIN + 50001, nop = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int price = prices[i];
            int sold = max(buyp + price - fee, holdp + price - fee);
            int buy = max(nop - price, soldp - price);
            int hold = max(buyp, holdp);
            int no = max(soldp, nop);
            
            soldp = sold;
            buyp = buy;
            holdp = hold;
            nop = no;
        }
        return max(soldp, nop);
    }
};
