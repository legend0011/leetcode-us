// https://leetcode.com/problems/two-sum/
// fllin, 20170608

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mapping;
    vector<int> result;
    for(auto i = 0; i < nums.size(); ++i) {
      auto second = target - nums[i];
      if(mapping.find(second) != mapping.end()) {
        result.push_back(mapping[second]);
        result.push_back(i);
        break;
      }      
      mapping[nums[i]] = i;
    }
        
    return result;
  }
};