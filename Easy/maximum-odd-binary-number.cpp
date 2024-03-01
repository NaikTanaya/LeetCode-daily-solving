class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.rbegin(),s.rend());
        for(int i = s.size()-1;i>=0;i--){
            if(s[i]=='1')swap(s[i],s[s.size()-1]);
        }
        return s;
    }
};

// Example 1:
// Input: s = "010"
// Output: "001"
// Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".

// Example 2:
// Input: s = "0101"
// Output: "1001"
// Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100". So the answer is "1001".
