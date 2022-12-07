/*
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

    Each substring is balanced.

Return the maximum number of balanced strings you can obtain
*/

#include <stack>
#include <string>

class Solution {
public:
    int balancedStringSplit(std::string s) {
        std::stack<char> balance;
        int counter = 0;
        for (auto c: s) {
            if(!balance.empty() && balance.top() != c) {
                balance.pop();
                if(balance.empty()) {
                    ++counter;
                }
            } else {
                balance.push(c);
            }
        }
        return counter;
    }
};