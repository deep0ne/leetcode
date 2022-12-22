#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int num_to_find = target - nums[i];
            if(hash.count(num_to_find)) {
                solution.push_back(i);
                solution.push_back(hash[num_to_find]);
                break;
            } else {
                hash[nums[i]] = i;
            }
        }   
        return solution;
    }
};