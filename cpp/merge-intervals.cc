// https://leetcode.com/problems/merge-intervals/#/description
// chi zhang, 2017-7-26

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& left, Interval& right) {
            return left.start < right.start;  // small -> big
        });
        vector<Interval> rs;
        if (intervals.empty()) {
            return rs;
        }
        rs.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= rs.back().end) {
                rs.back().end = max(rs.back().end, intervals[i].end);
            } else {
                rs.push_back(intervals[i]);
            }
        }
        return rs;
    }
};
