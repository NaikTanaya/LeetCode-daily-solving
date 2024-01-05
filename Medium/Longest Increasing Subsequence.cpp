class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int lis[n];

        lis[0] = 1;

        // Compute optimized LIS values in
        // bottom up manner
        for (int i = 1; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }

        // Return maximum value in lis[]
        return *max_element(lis, lis + n);
    }
};

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
