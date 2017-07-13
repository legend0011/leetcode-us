// https://leetcode.com/problems/3sum/
// fllin, 2017-7-13

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        const int target = 0;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for(auto i = nums.begin(); i < last -2; ++i) {
            auto j = i + 1;
            if(i > nums.begin() && *i == *(i - 1)) continue;
            auto k = last - 1;
            while(j < k) {
                if(*i + *j + *k < target) {
                    ++j;
                    while(j < k && *j == *(j - 1)) ++j;
                    
                } else if(*i + *j + *k > target) {
                    --k;
                    while(j < k && *k == *(k + 1)) --k;
                    
                } else {
                    res.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                    
                }
            }
            
        }
        
        return res;       
    }
};

