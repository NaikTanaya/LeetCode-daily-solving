class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        
        int ans = 1;
        sort(arr.begin(),arr.end());

        int lastpoint = arr[0][1];
        for(auto it : arr)
        {
            if(it[0]>lastpoint)
            {
                ans++;
                lastpoint = it[1];
            }
            lastpoint = min(it[1],lastpoint);
        
        }
        return ans;
    }
};

// Example 1:

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

// Example 2:

// Input: points = [[1,2],[3,4],[5,6],[7,8]]
// Output: 4
// Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

// Example 3:

// Input: points = [[1,2],[2,3],[3,4],[4,5]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
// - Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
