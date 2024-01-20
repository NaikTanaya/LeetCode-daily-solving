// need to look again 
class Solution {
public:
    // NOTE : kisi ek ko means (getNSL or getNSR) strictly increasing/decreasing
    // bnana h q ki duplicates bnege corner case m...ex : {2, 3, 4, 2, 3, 2}...
    vector<int> getNSL(vector<int>& arr, int n) {
        vector<int> ans(n); // answer storing purpose but this time we can say
                            // in this array has n size...
        stack<int> st; // stack is used to find next smallest in left side of
                       // arr in this problem...

        for (int i = 0; i < n; ++i) {
            if (st.empty())
                ans[i] = -1; // if stack is empty then, store -1 in arr...
            else
                while (!st.empty() &&
                       arr[st.top()] >
                           arr[i]) { // check jo element stack m present h woh
                                     // khi current se bda toh nhi if bda h then
                                     // pop kr do stack empty ho gyi to -1 arr m
                                     // insert kr do...
                    st.pop();
                }
            ans[i] = st.empty() ? -1 : st.top(); // otherwise stack ki top ko
                                                 // arr m insert kr do...
            st.push(i); // usse insert v krna stack mein...
        }
        return ans;
    }

    vector<int> getNSR(vector<int>& arr, int n) {
        vector<int> ans(n); // answer storing purpose but this time we can say
                            // in this array has n size...
        stack<int> st; // stack is used to find next smallest in right side of
                       // arr in this problem...

        for (int i = n - 1; i >= 0;
             --i) { // this time hum right se traverse krenge...
            if (st.empty())
                ans[i] = n; // if stack is empty then, store n in arr...
            else
                while (!st.empty() &&
                       arr[st.top()] >=
                           arr[i]) { // check jo element stack m present h woh
                                     // khi current se bda toh nhi if bda h then
                                     // pop kr do stack empty ho gyi to n arr m
                                     // insert kr do...
                    st.pop();
                }
            ans[i] = st.empty() ? n : st.top(); // otherwise stack ki top ko arr
                                                // m insert kr do...
            st.push(i); // usse insert v krna stack mein...
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n =
            arr.size(); // total numbers of element present in current array...

        vector<int> N_S_L =
            getNSL(arr, n); // this vector stores small values indices for each
                            // element in LEFT direction...
        vector<int> N_S_R =
            getNSR(arr, n); // this vector stores small values indices for each
                            // element in RIGHT direction...
        long long sum = 0;
        int M = 1e9 + 7; // for large value...

        // Traverse for each element in arr...
        for (int i = 0; i < n; ++i) {
            long long ls = i - N_S_L[i]; // left mein smallest element k indices
                                         // for every subarray...
            long long rs = N_S_R[i] - i; // right mein smallest element k
                                         // indices for every subarray...

            long long totalWays = ls * rs; // Total number of subarray...

            long long totalSum =
                arr[i] * totalWays; // coz, woh totalWays times smallest h...
            sum = (sum + totalSum) % M;
        }

        return sum;
    }
};

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
