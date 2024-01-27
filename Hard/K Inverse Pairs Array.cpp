class Solution {
private:
    const int mod=int(1e9+7);
public:
    int kInversePairs(int n, int k) {
        vector<int> prev(k+1,0),curr(k+1,0);
        prev[0]=curr[0]=1;
        for(int N=1;N<=n;++N) {
            for(int K=0;K<=k;++K) {
                curr[K] = (prev[K] + (K > 0 ? curr[K - 1] : 0)) % mod;
                curr[K] = (curr[K] + mod - (K >= N ? prev[K-N] : 0)) % mod;
            }
            prev = curr;
        }
        return curr[k];
    }
};

// Intuition
// Let's say we have n elements in our permutation then Depending on where we put the element (n+1) in our permutation, we may add 0, 1, 2, ..., n new inverse pairs. For example, if we have some permutation of 1...4, then:

// 5 x x x x creates 4 new inverse pairs
// x 5 x x x creates 3 new inverse pairs
// ...
// x x x x 5 creates 0 new inverse pairs
// Approach
// dp[n][k] = dp[n - 1][k - 0] + dp[n - 1][k - 1] + ... + dp[n - 1][k - (n - 1)]

// Complexity
// Time complexity: O(n∗k∗k)O(n*k*k)O(n∗k∗k) to O(n∗k)O(n*k)O(n∗k)

// Space complexity:O(n∗k)O(n*k)O(n∗k) to O(k)O(k)O(k)

// Optimization Idea
// f(n, k) = f(n-1, k) + f(n-1, k-1) + f(n-1, k-2) + ... + f(n-1, k-n+1) --->(1)

// f(n, k-1) = f(n-1, k-1) + f(n-1, k-2) + f(n-1, k-3) + ... + f(n-1, k-n+1)+ f(n-1, k-n) --->(2)

// subtract eqn 2 from eqn 1,we get

// f(n, k) = f(n, k-1) + f(n-1, k) - f(n-1, k-n)

// Example 1:

// Input: n = 3, k = 0
// Output: 1
// Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

// Example 2:

// Input: n = 3, k = 1
// Output: 2
// Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
