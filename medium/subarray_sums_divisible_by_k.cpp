/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

*/

#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int pref_sum = 0;
        vector<int> prefs(k);
        prefs[pref_sum]++;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            pref_sum = (pref_sum + nums[i]) % k; 
            
            if(pref_sum < 0) pref_sum += k; 
                        
            ans += prefs[pref_sum]; 
            
            prefs[pref_sum]++; 
        }
        
        return ans;
    }
};
