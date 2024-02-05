class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> freq_map;
        
        // Count character frequencies
        for (char c : s) {
            freq_map[c]++;
        }
        
        // Find the first unique character
        for (int i = 0; i < s.length(); ++i) {
            if (freq_map[s[i]] == 1) {
                return i;
            }
        }
        
        // If no unique character is found
        return -1;
    }
};

// Example 1:

// Input: s = "leetcode"
// Output: 0

// Example 2:

// Input: s = "loveleetcode"
// Output: 2

// Example 3:

// Input: s = "aabb"
// Output: -1
 
