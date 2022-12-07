/*
You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

    answer[0] is a list of all players that have not lost any matches.
    answer[1] is a list of all players that have lost exactly one match.

The values in the two lists should be returned in increasing order.

Note:

    You should only consider the players that have played at least one match.
    The testcases will be generated such that no two matches will have the same outcome.


-----NAIVE MEMORY APPROACH, FIX THIS------
*/

#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::vector<std::vector<int>> ans(2);
        std::map<int, std::vector<int>> win_lose, lose_win;
        for(int i = 0; i < matches.size(); ++i) {
            win_lose[matches[i][0]].push_back(matches[i][1]);
            lose_win[matches[i][1]].push_back(matches[i][0]);
        }

        for (auto& [key, _]: win_lose) {
            if (lose_win.count(key) == 0) {
                ans[0].push_back(key);
            }
        }

        for (auto& [key, _]: lose_win) {
            if(lose_win[key].size() == 1) {
                ans[1].push_back(key);
            }
        }
 
    return ans;

    }
};