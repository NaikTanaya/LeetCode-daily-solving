class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int length = neededTime.size();
        int left = 0;
        int totalCost = 0;
        for (int i = 1; i < length; i++) {
            if (colors[left] == colors[i]) {
                if (neededTime[left] < neededTime[i]) {
                    totalCost += neededTime[left];
                    left = i;
                } else {
                    totalCost += neededTime[i];
                }

            } else {
                left = i;
            }
        }

        return totalCost;
    }
};

// Example 1:
// Input: colors = "abaac", neededTime = [1,2,3,4,5]
// Output: 3
// Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
// Bob can remove the blue balloon at index 2. This takes 3 seconds.
// There are no longer two consecutive balloons of the same color. Total time = 3.

// Example 2:

// Input: colors = "abc", neededTime = [1,2,3]
// Output: 0
// Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.

// Example 3:

// Input: colors = "aabaa", neededTime = [1,2,3,4,1]
// Output: 2
// Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
// There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.

Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
