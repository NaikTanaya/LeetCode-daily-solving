// got 100% tc
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            // odd length palindromes
            int cnt = 0;
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt++;
                l--, r++;
            }
            ans += cnt;

            // even length palindromes
            l = i, r = i+1, cnt = 0;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt++;
                l--, r++;
            }
            ans += cnt;
        }
        return ans;
    }
};

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
