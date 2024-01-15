class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Maps to store the count of losses for each player
        map<int, int> lostCount;

        // Process matches and update maps
        for (auto& match : matches) {
            int pWin = match[0], pLost = match[1];

            // Increment the lost count for the losing player
            lostCount[pLost]++;

            // Initialize the lost count for the winning player if not found
            if (lostCount.find(pWin) == lostCount.end()) {
                lostCount[pWin] = 0;
            }
        }
        vector<int> zeroLost, oneLost;
        for (auto p : lostCount) {
            if (p.second == 0) {
                zeroLost.push_back(p.first);
            }
            if (p.second == 1) {
                oneLost.push_back(p.first);
            }
        }

        return {zeroLost, oneLost};
    }
};

// Example 1:

// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

// Example 2:

// Input: matches = [[2,3],[1,3],[5,4],[6,4]]
// Output: [[1,2,5,6],[]]
// Explanation:
// Players 1, 2, 5, and 6 have not lost any matches.
// Players 3 and 4 each have lost two matches.
// Thus, answer[0] = [1,2,5,6] and answer[1] = [].
