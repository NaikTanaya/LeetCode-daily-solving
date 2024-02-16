class Solution {
public:

    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto a : arr)mp[a]++;
        
        vector<int>v;
        int cnt=0;
        for(auto a :mp){
            v.push_back(a.second);
        }
        sort(v.begin(),v.end());
        for(int i =0;i<v.size();i++){
            if(k > v[i]){
                k-=v[i];
                v[i]=0;
            }else{
                v[i] -= k;
                k =0;
            }
            if(v[i]!=0)cnt++;
        }

        return cnt;

    }
};



// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
