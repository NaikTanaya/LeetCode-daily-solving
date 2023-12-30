class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // Count the frequency of each character
        unordered_map<char, int> charFrequency;

        for (const string& str : words) {
            for (char c : str) {
                charFrequency[c]++;
            }
        }

        // Check if the frequencies can be evenly distributed
        for (const auto& entry : charFrequency) {
            if (entry.second % words.size() != 0) {
                return false;
            }
        }

        return true;
    }
};

// Example 1:

// Input: words = ["abc","aabc","bc"]
// Output: true
// Explanation: Move the first 'a' in words[1] to the front of words[2],
// to make words[1] = "abc" and words[2] = "abc".
// All the strings are now equal to "abc", so return true.

// Example 2:

// Input: words = ["ab","a"]
// Output: false
// Explanation: It is impossible to make all the strings equal using the operation.
