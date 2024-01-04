class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        int s = 0;
        while(s < nums.size()){
            int e = s;
            
            while(e < nums.size() && nums[e] == nums[s]) {
                e++;
            }
            int count = e-s;
            if(count == 1) return -1;
            res += count/3;

            if(count%3 != 0) res++;
            s=e;
        }
        return res;
    }
};



class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto a: nums){
            mp[a]++;
        }

        int count=0;
        for(auto a: mp){
            int t = a.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};



// Example 1:

// Input: nums = [2,3,3,2,2,4,2,3,4]
// Output: 4
// Explanation: We can apply the following operations to make the array empty:
// - Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
// - Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
// - Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
// - Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
// It can be shown that we cannot make the array empty in less than 4 operations.

// Example 2:

// Input: nums = [2,1,2,2,3,3]
// Output: -1
// Explanation: It is impossible to empty the array.
