#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return minDepth(root->right) + 1;

    if (root->right == NULL)
        return minDepth(root->left) + 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);

    if (leftDepth < rightDepth)
        return leftDepth + 1;

    return rightDepth + 1;
}