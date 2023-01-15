#include <vector>
#include <cstdint>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int counter = 0;
        
        if(n == 0 || n == 1) {
            return 0;
        }
        vector<int> nums(n+1);
        for(auto i = 0; i < n; ++i) {
            nums[i] = i;
        }
        nums[0] = 0;
        nums[1] = 0;
        for(int64_t num = 2; num < n; ++num) {
            if(nums[num]) {
                for (int64_t j = num*num; j < n + 1; j += num) {
                    nums[j] = 0;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i]) {
                ++counter;
            }
        }
        return counter;
    }
};