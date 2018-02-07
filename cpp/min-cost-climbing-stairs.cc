// https://leetcode.com/problems/min-cost-climbing-stairs/description/
// chi zhang, 2018.2.7

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) {
            return cost[0];
        }
        cost.push_back(0);
        for (int i = 2; i < cost.size(); ++i) {
            cost[i] += std::min(cost[i-1], cost[i-2]);
        }
        return cost[cost.size() - 1];
    }
};
