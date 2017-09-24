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
        vector<Interval> ans;
        if (intervals.size() < 1) {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), 
             [](Interval a, Interval b)->bool {
            return a.start < b.start;
        });
        ans.push_back(intervals[0]);
        int i = 1;
        while (i < intervals.size()) {
            if (intervals[i].start > ans.back().end) {
                ans.push_back(intervals[i]);
            } else if (ans.back().end < intervals[i].end) {
                ans.back().end = intervals[i].end;
            }
            ++i;
        }
        return ans;
    }
};