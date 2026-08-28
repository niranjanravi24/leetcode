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
    void f(TreeNode* root, vector<int>& values){
        if(!root) return;

        values.push_back(root->val);
        f(root->left, values);
        f(root->right, values);

    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        f(root, values);
        return values;
    }
};