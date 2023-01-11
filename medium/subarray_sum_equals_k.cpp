/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

*/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        vector<int> prefix_sum = nums;
        for(int i = 1; i < prefix_sum.size(); ++i) {
            prefix_sum[i] += prefix_sum[i-1];
        }
        unordered_map<int, int> hashmap;
        for (int i = 0; i < prefix_sum.size(); ++i) {
            if (prefix_sum[i] == k) {
                ++total;
            }
            if(hashmap.count(prefix_sum[i] - k)) {
                total += hashmap[prefix_sum[i] - k];
            }
            hashmap[prefix_sum[i]]++;
        }
        return total;
    }
};