class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        int count1[26] = {0};
        int count2[26] = {0};
        for (int i = 0; i < word1.length(); i++) // counting freq of word1 chars
        {
            count1[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.length(); i++) // counting freq of word2 chars
        {
            count2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) 
        // checking if atleast chars are present in both strings
        //eka word mdhe char ahe and ekat nsel tr return false
        {
            if (count1[i] && count2[i] == 0)
                return false;
        }

        sort(count1, count1 + 26);
        sort(count2, count2 + 26);

        for (int i = 0; i < 26;i++) 
                // checking whether the frequencies present in word1 matches
                // with word2, no matter which char freq it is
        {
            if (count1[i] != count2[i])
                return false;
        }
        return true;
    }
};

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"

// Example 2:

// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.

// Example 3:

// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"
