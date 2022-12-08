/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
*/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums;
        }
        vector<int> running;
        running.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            running.push_back(running.back() + nums[i]);
        }
        return running;
    }
};