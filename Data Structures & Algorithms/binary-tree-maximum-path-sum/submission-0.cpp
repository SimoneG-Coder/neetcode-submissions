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
    int maxSum;
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromNode(root);
        return maxSum;
    }

    int gainFromNode(TreeNode* node){
        if(!node) return 0;

        int leftGain = max(gainFromNode(node->left), 0);
        int rightGain = max(gainFromNode(node->right), 0);

        int currentSum = node->val + leftGain + rightGain;
        maxSum = max(currentSum, maxSum);

        return node->val + max(leftGain, rightGain);

    }
};
