/*
Given an array of intervals where intervals[i] = [starti, endi],
merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end()); // nlogn
        ans.push_back(intervals[0]);
        for (int i = 1, j = 0; i < intervals.size(); ++i) {
            if(ans[j][1] >= intervals[i][0]) {
                ans[j][1] = std::max(ans[j][1], intervals[i][1]);
            } else {
                ++j;
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};