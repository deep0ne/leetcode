/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                solution.push_back(nums1[i]);
                ++j;
                ++i;
                while(i < nums1.size() && nums1[i] == nums1[i-1]) {
                    ++i;
                }
                while(j < nums2.size() && nums2[j] == nums2[j-1]) {
                    ++j;
                }
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return solution;
    }
};