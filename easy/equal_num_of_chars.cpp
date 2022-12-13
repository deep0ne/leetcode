/*
Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
*/

#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::unordered_map<char, int> occurences;
        for(auto c: s) {
            occurences[c]++;
        }
        int num_of_occurences = occurences[s[0]];
        for (auto& [_, occurence]: occurences) {
            if (occurence != num_of_occurences) {
                return false;
            }
        }
        return true;
    }
};