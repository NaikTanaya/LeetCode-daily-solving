class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        string str="";

        for (char c : s) {
            freq[c]++;
        }
          // Find the character with the most frequency.
        while (!freq.empty()) {
            auto max_it = max_element(freq.begin(), freq.end(),
                                    [](const pair<char, int> &p1, const pair<char, int> &p2) {
                                        return p1.second < p2.second;
                                    });

            // Append the character with the most frequency to the string.
            char max_char = max_it->first;
            int max_freq = max_it->second;
            str.append(max_freq, max_char);

            // Erase the character from the map.
            freq.erase(max_it);
        }

    return str;
    }
};

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
