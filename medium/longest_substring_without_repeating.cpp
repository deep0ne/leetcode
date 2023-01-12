#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t counter = 0;
        string substring;
        std::unordered_set<char> characters;
        for(int i = 0; i < s.size(); ++i) {
            if(characters.count(s[i]) == 0) {
                characters.insert(s[i]);
                substring += s[i];
            } else {
                if(substring.size() > counter) {
                    counter = substring.size();
                }
                substring.clear();
                characters.clear();
                substring += s[i-1];
                substring += s[i];
                characters.insert(s[i-1]);
                characters.insert(s[i]);
            }
        }
        return std::max(substring.size(), counter);
    }
};

int main() {
    Solution solution;
    solution.lengthOfLongestSubstring("dvdf");
}