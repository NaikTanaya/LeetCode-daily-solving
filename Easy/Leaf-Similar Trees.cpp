/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        stack<TreeNode*> s1,s2;
        s1.push(root1);
        s2.push(root2);
        while(!s1.empty() && !s2.empty())
        {
            if(dfs(s1) != dfs(s2))
            {
                return false;
            }
        }
        return s1.empty() && s2.empty();
             
}
    int dfs(stack<TreeNode*>&s)
    {
        while(true)
        {
            TreeNode* node= s.top(); 
            s.pop();
            if(node->right)
            {
                s.push(node->right);
            }
            if(node->left)
            {
                s.push(node->left);
            }
            if(!node->left && !node->right)
            {
                return node->val;
            }
        }
    }
};

// Example 1:

// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true

// Example 2:

// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
