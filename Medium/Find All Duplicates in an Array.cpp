class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num =abs(nums[i]);
            int idx = num - 1;
            if(nums[idx] < 0)
                result.push_back(num);
            
            nums[idx] *= -1;
        }
        return result;
    }
};

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

// Example 2:

// Input: nums = [1,1,2]
// Output: [1]

// Example 3:

// Input: nums = [1]
// Output: []
