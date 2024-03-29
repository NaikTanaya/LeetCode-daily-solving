class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode *slow=list1;
        ListNode *fast=list1;
        ListNode *last=list2;
        
        for(int i=0;i<=b;i++){
            if(i<a-1){
                slow=slow->next;
            }
            fast=fast->next;
        }
        while(last->next){
            last=last->next;
        }
        slow->next=list2;
        last->next=fast;
        
        return list1;
    
    }
};

// Example 1:

// Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// Output: [10,1,13,1000000,1000001,1000002,5]
// Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

// Example 2:

// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
// Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
// Explanation: The blue edges and nodes in the above figure indicate the result.
