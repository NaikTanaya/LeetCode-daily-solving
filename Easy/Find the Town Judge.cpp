
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> in(N + 1), out(N + 1);
		for (auto a : trust) {
			++out[a[0]];
			++in[a[1]];
		}
		for (int i = 1; i <= N; ++i) {
			if (in[i] == N - 1 && out[i] == 0) return i;
		}
		return -1;
    }
};

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2

// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3

// Example 3:

// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1
