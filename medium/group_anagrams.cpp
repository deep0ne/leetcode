/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        std::map<string, vector<string>> container;
        for(auto& word: strs) {
            string to_sort = word;
            sort(to_sort.begin(), to_sort.end());
            container[to_sort].push_back(word);
        }
        
        for(auto& [_, words]: container) {
            ans.push_back(words);
        }
        return ans;
    }
};