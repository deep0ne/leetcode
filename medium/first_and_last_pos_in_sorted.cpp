/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

*/

#include <vector>
using namespace std;

class Solution {
public:

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (r - l) / 2 + l;
            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int second = lower_bound(nums, target + 1) - 1;
        if(first <= second) {
            return {first, second};
        } else {
            return {-1, -1};
        }
    }
};