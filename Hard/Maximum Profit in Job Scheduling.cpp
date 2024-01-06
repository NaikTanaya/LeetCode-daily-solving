class Solution {
public:
    int memo[50001]; //memoization
    int n;
    
    // binary search for finding 1st job jiska st >= currentJob ka endTime
    int getNextIndex(vector<vector<int>> &combine, int l,int end)
    {
        int r=n-1;
        int result=n+1; //put random value 
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(combine[mid][0] >= end) //we can take this task
            {
                result=mid;
                r=mid-1;   // if dup like {1,2,3,3} then we will choose first value
            }
            else
            {
                l=mid+1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>> &combine, int i)
    {
        if(i >= n)
        {
            return 0;
        }
        if(memo[i]!= -1)
        {
            return memo[i];
        }


        // if taken =profit + solve(nextjob which is endingTime of previous as the startTime of current job)
        // i+1 cause next index pasun , combine[index][1] means end time
        int next=getNextIndex(combine,i+1,combine[i][1]);
        int taken=combine[i][2] + solve(combine,next);

        // if not taken move the index+1
        int not_taken=solve(combine,i+1);
        return memo[i] = max(taken,not_taken);  //memo
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(memo,-1,sizeof(memo));


        // now zip all st,et,profit and form a new vect<vect>
        // made all elements 0 for now for all subvectors
        vector<vector<int>> combine(n,vector<int>(3,0));

        for(int i=0;i<n;i++)
        {
            combine[i][0]=startTime[i];
            combine[i][1]=endTime[i];
            combine[i][2]=profit[i];
        }

        //sort as per st
        auto comp = [&](auto& vec1, auto& vec2) {
              return vec1[0] <= vec2[0];
        };
        
        //sort kardo according to sart time
        //sort as per st
        sort(begin(combine), end(combine), comp);
        //index 0 se start
        return solve(combine,0);
    }
};


// Example 1:

// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

// Example 2:

// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.

// Example 3:

// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6
