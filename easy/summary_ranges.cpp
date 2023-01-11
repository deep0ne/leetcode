/*
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        string range;
        for(int i = 0, j = 0; i < nums.size(); i = ++j) {
            while(j + 1 < nums.size() && nums[j + 1] == nums[j] + 1) {
                ++j;
            }
            range = to_string(nums[i]);
            if (j > i) {
                range += "->" + to_string(nums[j]);
            }
            ranges.push_back(range);
        }
        return ranges;
    }
};