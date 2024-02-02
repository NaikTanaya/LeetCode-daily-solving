class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> res;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                int num = stoi(s.substr(i, j - i + 1));

                if (num > high)
                    break;
                if (low <= num)
                    res.push_back(num);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
