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
    int diameterOfBinaryTree(TreeNode* root) {
        int largestDiameter = 0;
        height(root, largestDiameter);
        return largestDiameter;
    }

    int height(TreeNode* root, int &largestDiameter){
        if(!root) return 0;

        int leftHeight = height(root->left, largestDiameter);
        int rightHeight = height(root->right, largestDiameter);

        int diameter = leftHeight + rightHeight;
        largestDiameter = max(diameter, largestDiameter);

        return 1 + max(leftHeight, rightHeight);

    }
};
