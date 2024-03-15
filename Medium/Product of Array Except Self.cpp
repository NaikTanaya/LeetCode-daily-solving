
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix and suffix method

        int len=nums.size();
        vector<int> result(len,1);
        int prefix=1;
        int suffix=1;
        for(int i=0;i<len;i++)
        {
            result[i]*=prefix;
            prefix*=nums[i];
            
        }

        for(int i=len-1;i>=0;i--)
        {
            result[i]*=suffix;
            suffix*=nums[i];
            
        }

        return result;


        //using logarithmic solution
        // int len=nums.size();
        // vector<int> result(len,0);
        // int log_prod=0;

        // for(int i=0;i<len;i++)
        // {
        //     log_prod+=log(nums[i]);
        // }

        // // res = e^(log_product * log[nums[i]])
        // for(int i=0;i<len;i++)
        // {
        //     result[i]=e^(log_prod*log(nums[i]));
        // }
        // return result;
    }
};
