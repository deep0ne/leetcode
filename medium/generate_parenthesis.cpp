#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    void generate_pair(vector<string>& solution, int n, int m, string prefix) {
        if(n == 0 && m == 0) {
            solution.push_back(prefix);
        } else {
            if(n > 0) {generate_pair(solution, n-1, m+1, prefix+'(');} // add left parenthesis and increment count of close brackets to be add
            if(m > 0) {generate_pair(solution, n, m-1, prefix+')');} // add closing brackets and decrease its counter
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        generate_pair(answer, n, 0, "");
        return answer;
    }
};