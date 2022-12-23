/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(!isalpha(s[l]) && !isdigit(s[l])) {
                ++l;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r])) {
                --r;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};