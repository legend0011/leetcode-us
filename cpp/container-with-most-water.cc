// https://leetcode.com/problems/container-with-most-water/#/description
// chi zhang, 2017-6-14
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            int area = (j - i) * min(height[i], height[j]);
            max_area = area > max_area ? area : max_area;
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max_area;
    }
};
