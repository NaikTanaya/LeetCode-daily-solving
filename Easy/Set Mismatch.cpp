class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> seen;
        int duplicate = -1;
        int n = nums.size();

        // Step 1: Find the Duplicate
        for (int num : nums) {
            if (seen.count(num)) {
                duplicate = num;
            } else {
                seen.insert(num);
            }
        }

        // Step 2: Find the Missing Number
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        int missing = expectedSum - (actualSum - duplicate);

        result.push_back(duplicate);
        result.push_back(missing);

        return result;
    }
};

// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]

// Example 2:

// Input: nums = [1,1]
// Output: [1,2]
