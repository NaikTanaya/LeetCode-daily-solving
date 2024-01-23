// revision is needed
class Solution {
    int dfs(int idx, vector<string>& arr, vector<int> vis) {
        if (idx == arr.size())
            return 0;
        int skip = dfs(idx + 1, arr, vis);
        for (char c : arr[idx]) {
            if (vis[c - 'a'])
                return skip;
            vis[c - 'a'] = 1;
        }
        int noskip = arr[idx].length() + dfs(idx + 1, arr, vis);
        return max(skip, noskip);
    }

public:
    int maxLength(vector<string>& arr) {
        vector<int> vis(26, 0);
        return dfs(0, arr, vis);
    }
};

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.

// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.
