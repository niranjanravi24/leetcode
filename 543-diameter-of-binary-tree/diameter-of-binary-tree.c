/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root, int* diameter){
    if(!root) return 0;
    
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    int sum = lh+rh;
    if(sum > *diameter){
        *diameter = sum;
    }
    int maxi = (lh>rh) ? lh:rh;
    return 1+maxi;

}
int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}