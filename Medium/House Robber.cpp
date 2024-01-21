// need to do again
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int> s0(2, 0);
        vector<int> s1(2, 0);
        s1[0] = nums[0];

        for (int i = 1; i < n; i++) {
            s0[i % 2] = max(s0[(i - 1) % 2], s1[(i - 1) % 2]);
            s1[i % 2] = s0[(i - 1) % 2] + nums[i];
        }

        return max(s0[(n - 1) % 2], s1[(n - 1) % 2]);
    }
};


// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
