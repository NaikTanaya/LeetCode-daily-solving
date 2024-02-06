class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;                        // Vector to store the final result 
        unordered_map<string, vector<string>> mp;         // Create an unordered_map to map sorted strings
        for(int i = 0; i < strs.size(); i++) {           // Iterate through each string
            string s = strs[i];                         // Store the original string
            sort(strs[i].begin(), strs[i].end());      // Sort the characters in the string to identify anagrams
            mp[strs[i]].push_back(s);                 // Map the sorted string to its original string in the unordered_map
        }
        for(auto i : mp)                          // Iterate through the unordered_map and push the grouped anagrams to the result vector
            ans.push_back(i.second);
        
        return ans;      // Return the final result
    }
};

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:

// Input: strs = [""]
// Output: [[""]]

// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
