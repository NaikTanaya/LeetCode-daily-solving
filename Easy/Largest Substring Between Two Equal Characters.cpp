class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> lastPosition;
        int maxLength = -1;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (lastPosition.find(currentChar) != lastPosition.end()) {
                // If the character is found, update the maximum length
                maxLength = max(maxLength, i - lastPosition[currentChar] - 1);
            } else {
                // If the character is not found, store its position
                lastPosition[currentChar] = i;
            }
        }

        return maxLength;
    }
};

// Example 1:

// Input: s = "aa"
// Output: 0
// Explanation: The optimal substring here is an empty substring between the two 'a's.

// Example 2:

// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".

// Example 3:

// Input: s = "cbzxy"
// Output: -1
// Explanation: There are no characters that appear twice in s.
