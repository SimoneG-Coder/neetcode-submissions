/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        stack<pair<TreeNode*, int>> st;
        st.push({root, INT_MIN});

        while(!st.empty()){
            auto[curr, largest] = st.top();
            st.pop();
            if(curr->val >= largest) count++;
            largest = max(largest, curr->val);
            if(curr->left) st.push({curr->left, largest});
            if(curr->right) st.push({curr->right, largest});
        }
        return count;
    }
};
