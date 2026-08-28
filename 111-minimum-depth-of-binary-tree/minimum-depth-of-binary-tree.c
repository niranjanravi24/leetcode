/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(!root) return 0;

    int left = minDepth(root->left);
    int right = minDepth(root->right);
    int mini = INT_MAX;
    if(!left){
        mini = right;
    }
    else if(!right){
        mini = left;
    }
    else{
        mini = (left<right) ? left:right;
    } 

    return 1+mini;
}