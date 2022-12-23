#include <algorithm>
#include <vector>

using namespace std;

/*
 First Solution:
 Reorders the elements in the range [first, last) in such a way that all elements for which the predicate p returns true
 precede the elements for which predicate p returns false. Relative order of the elements is preserved.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::stable_partition(nums.begin(), nums.end(), [](const auto num) {return num != 0;});
    }
};
*/

/*
 Second solution:
 if num != 0, swap it with next, which will not increment when the num is zero
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, next = 0; i < nums.size(); ++i) {
            if(nums[i]) {std::swap(nums[i], nums[next++]);}
        }
    }
};
