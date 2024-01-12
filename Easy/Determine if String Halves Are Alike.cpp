class Solution {
public:
    bool halvesAreAlike(string s) {
        string count1="";
        string count2="";
        int res1=0;
        int res2=0;
        int half=s.size()/2;
        for(int i=0;i<half;i++)
        {
            count1+=s[i];
        }
        for(int i=half;i<s.size();i++)
        {
            count2+=s[i];
        }
        for(int i=0; i<count1.size() && count2.size();i++)
        {
            if(count1[i] == 'a' || count1[i] == 'e' ||count1[i] == 'i' ||count1[i] == 'o' ||count1[i] == 'u' || count1[i] == 'A' || count1[i] == 'E' ||count1[i] == 'I' ||count1[i] == 'O' ||count1[i] == 'U')
            {
                res1++;
            }
             if(count2[i] == 'a' || count2[i] == 'e' ||count2[i] == 'i' ||count2[i] == 'o' ||count2[i] == 'u'|| count2[i] == 'A' || count2[i] == 'E' ||count2[i] == 'I' ||count2[i] == 'O' ||count2[i] == 'U')
            {
                res2++;
            }
        }

        return res1==res2;
    }
};

// Example 1:

// Input: s = "book"
// Output: true
// Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.

// Example 2:

// Input: s = "textbook"
// Output: false
// Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
// Notice that the vowel o is counted twice.
