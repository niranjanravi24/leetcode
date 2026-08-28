/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(!root) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int maxi = (left > right) ? left : right;

    return 1 + maxi;
}