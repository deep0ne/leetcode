#include <vector>
#include <iostream>
#include <cassert>

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

// [1,1,1,0,0,0,1,1,1,1,0]

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int l = 0, max_count = 0, zero_count = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                ++zero_count;
            }
            while(zero_count > k) {
                if(nums[l] == 0) {
                    --zero_count;    
                }
                ++l;
            }
            max_count = std::max(max_count, r - l + 1); 
        }
        return max_count;
    }
};

int main() {
    Solution sol;
    std::vector<int> test = {1,1,1,0,0,0,1,1,1,1,0};
    assert(sol.longestOnes(test, 2) == 6);
}