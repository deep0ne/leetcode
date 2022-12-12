/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewels_count = 0;
        unordered_set<char> jewels_set;
        for (auto c: jewels) {
            jewels_set.insert(c);
        }
        for(auto stone: stones) {
            if (jewels_set.count(stone)) {
                ++jewels_count;
            }
        }
        return jewels_count;
    }
};