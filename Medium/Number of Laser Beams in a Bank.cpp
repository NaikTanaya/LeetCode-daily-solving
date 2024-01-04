class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
    int m = bank.size();
    int n = bank[0].size();
    int totalCount = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            bool validBeam = true;
            for (int k = i + 1; k < j; ++k) {
                if (bank[k].find('1') != std::string::npos) {
                    validBeam = false;
                    break;
                }
            }

            if (validBeam) {
                totalCount += std::count(bank[i].begin(), bank[i].end(), '1') * std::count(bank[j].begin(), bank[j].end(), '1');
            }
        }
    }

    return totalCount;
    }
};

// Example 1:

// Input: bank = ["011001","000000","010100","001000"]
// Output: 8
// Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
//  * bank[0][1] -- bank[2][1]
//  * bank[0][1] -- bank[2][3]
//  * bank[0][2] -- bank[2][1]
//  * bank[0][2] -- bank[2][3]
//  * bank[0][5] -- bank[2][1]
//  * bank[0][5] -- bank[2][3]
//  * bank[2][1] -- bank[3][2]
//  * bank[2][3] -- bank[3][2]
// Note that there is no beam between any device on the 0th row with any on the 3rd row.
// This is because the 2nd row contains security devices, which breaks the second condition.

// Example 2:

// Input: bank = ["000","111","000"]
// Output: 0
// Explanation: There does not exist two devices located on two different rows.
