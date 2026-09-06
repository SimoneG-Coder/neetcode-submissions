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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(!curr){
                ans += "#,";
                continue;
            }

            ans += to_string(curr->val) + ",";
            q.push(curr->left);
            q.push(curr->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        vector<string> tokens;
        string token;
        for(char c: data){
            if(c == ','){
                tokens.push_back(token);
                token.clear();
            }else{
                token.push_back(c);
            }
        }

        if(tokens[0] == "#") return nullptr;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int i=1;

        while(!q.empty() && i<tokens.size()){
            TreeNode* curr = q.front();
            q.pop();

            if(tokens[i] != "#"){
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;

             if(i<tokens.size() && tokens[i] != "#"){
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};
