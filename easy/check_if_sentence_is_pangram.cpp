/*
A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise
*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        std::unordered_set<char> letters(sentence.begin(), sentence.end());
        return letters.size() == 26 ? true : false;
    }
};