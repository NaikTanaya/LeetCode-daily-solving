class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<long, vector<int>> map;

        for (int i = 0; i < n; i++) {
            long temp = nums[i];
            if (!map.count(temp)) {
                map[temp] = vector<int>();
            }
            map[temp].push_back(i);
        }

        int sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long a = 2L * nums[i] - nums[j];
                if (map.count(a)) {
                    for (int k : map[a]) {
                        if (k < i) {
                            dp[i][j] += dp[k][i] + 1;
                        } else {
                            break;
                        }
                    }
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};

// Example 1:

// Input: nums = [2,4,6,8,10]
// Output: 7
// Explanation: All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]

// Example 2:

// Input: nums = [7,7,7,7,7]
// Output: 16
// Explanation: Any subsequence of this array is arithmetic.
