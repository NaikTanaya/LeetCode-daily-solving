class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        vector< long long > times(n,0);
        sort(meetings.begin(),meetings.end());

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0], end = meetings[i][1];
            bool flag = false;
            int minind = -1;
            long long val = 1e18;
            for(int j=0;j<n;j++){
                if(times[j]<val) val = times[j], minind = j;
                if(times[j] <= start){
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if(!flag){
                ans[minind]++;
                times[minind]+=(1ll*(end-start));
            }
        }
        int maxi = -1, id = -1;
        for(int i =0;i<n;i++){
            if(ans[i]>maxi) maxi = ans[i], id = i;
        }
        return id;
    }
};


// Example 1:

// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
// Output: 0
// Explanation:
// - At time 0, both rooms are not being used. The first meeting starts in room 0.
// - At time 1, only room 1 is not being used. The second meeting starts in room 1.
// - At time 2, both rooms are being used. The third meeting is delayed.
// - At time 3, both rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
// - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
// Both rooms 0 and 1 held 2 meetings, so we return 0. 

// Example 2:

// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
// Output: 1
// Explanation:
// - At time 1, all three rooms are not being used. The first meeting starts in room 0.
// - At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
// - At time 3, only room 2 is not being used. The third meeting starts in room 2.
// - At time 4, all three rooms are being used. The fourth meeting is delayed.
// - At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
// - At time 6, all three rooms are being used. The fifth meeting is delayed.
// - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
// Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
