#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> letters;
        int i = 0, j = 0, counter_max = 0;
        while(i < s.size() && j < s.size()) {
            if(letters.count(s[j]) == 0) {
                letters.insert(s[j++]);
                counter_max = std::max(counter_max, static_cast<int>(letters.size()));
            } else {
                letters.erase(s[i++]);
            }
        }
        return counter_max;
    }
};