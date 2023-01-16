/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        // 4 5 9 -- 4 4 8 9 9
            
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                solution.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums2[j] > nums1[i]) {
                ++i;
            } else {
                ++j;
            }
        }
    
        return solution;
    }
};