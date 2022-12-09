/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(nums[l] >= target) {
            return l;
        } else {
            return l+1;
        }
    }
};