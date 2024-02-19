class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }
};

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16

// Example 3:

// Input: n = 3
// Output: false
