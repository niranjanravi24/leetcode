int** levelOrder(struct TreeNode* root, int* returnSize,
                 int** returnColumnSizes) {

    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int rows = 2000;

    int** ans = malloc(rows * sizeof(int*));

    *returnColumnSizes = malloc(rows * sizeof(int));

    struct TreeNode** queue = malloc(rows * sizeof(struct TreeNode*));

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {

        int size = rear - front;

        ans[level] = malloc(size * sizeof(int));

        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {

            struct TreeNode* node = queue[front++];

            ans[level][i] = node->val;

            if (node->left) {
                queue[rear++] = node->left;
            }

            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        level++;
    }

    *returnSize = level;

    free(queue);

    return ans;
}