/*
Given a string s consisting of lowercase English letters, return the first letter to appear twice.

Note:

    A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
    s will contain at least one letter that appears twice.

*/

#include <map>
#include <string>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> occur;
        char ans;
        for (auto c: s) {
            if(occur[c] == 1) {
                ans = c;
                return c;
            } else {
                ++occur[c];
            }
        }
        return ans;
    }
};