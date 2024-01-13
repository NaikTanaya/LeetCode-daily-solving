class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> freq;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for(auto p: freq)
        {
            if(p.second > 0)
            {
                ans+=p.second;
            }
        }
        return ans;
    }
};

// Example 1:

// Input: s = "bab", t = "aba"
// Output: 1
// Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

// Example 2:

// Input: s = "leetcode", t = "practice"
// Output: 5
// Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

// Example 3:

// Input: s = "anagram", t = "mangaar"
// Output: 0
// Explanation: "anagram" and "mangaar" are anagrams. 
