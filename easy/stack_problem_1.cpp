/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

    An integer x.
        Record a new score of x.
    '+'.
        Record a new score that is the sum of the previous two scores.
    'D'.
        Record a new score that is the double of the previous score.
    'C'.
        Invalidate the previous score, removing it from the record.

Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.
*/

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> container;
        for (auto c: operations) {
            if (c == "C") {
                container.pop();
            }
            else if (c == "D") {
                container.push(container.top() * 2);
            }
            else if (c == "+") {
                int first = container.top();
                container.pop();
                int second = container.top();
                container.push(first);
                container.push(first + second);
            } else {
                container.push(stoi(c));
            }
        }
        while(!container.empty()) {
            sum += container.top();
            container.pop();
        }
        return sum;
    }
};