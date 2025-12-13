struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define VISITED (void *) 0x1

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root)
        return NULL;
    int *ret = (int *) malloc(100 * sizeof(int));
    if (!ret) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    struct TreeNode *stack[100];
    int top = 0;

    do {
        left:    // Left label because I am too lazy to set and check flags
        while (root->left && root->left != VISITED) {
            // Push
            stack[top++] = root;
            root = root->left;
            (stack[top - 1])->left = VISITED;
        }

        inorder:
        ret[(*returnSize)++] = root->val;

        right:
        if (root->right && root->right != VISITED) {
            if (root->left != VISITED) {
                // Push
                stack[top++] = root;
                root = root->right;
                (stack[top - 1])->right = VISITED;
            } else {
				struct TreeNode *temp = root;
                root = root->right;
				temp->right = VISITED;
            }
            goto left;
        }
        // Pop
        if (top > 0) {
            root = stack[--top];
			goto inorder;
        }
    } while (top > 0);
    
    return ret;
}

int main(void)
{
	struct TreeNode root;
	root.val = 1;
	root.left = malloc(sizeof(struct TreeNode));
	root.left->val = 2;
	root.left->left = malloc(sizeof(struct TreeNode));
	root.left->left->val = 4;
	root.left->left->left = root.left->left->right = NULL;
	root.left->right = malloc(sizeof(struct TreeNode));
	root.left->right->val = 5;
	root.left->right->left = malloc(sizeof(struct TreeNode));
	root.left->right->left->val = 6;
	root.left->right->left->left = root.left->right->left->right = NULL;
	root.left->right->right = malloc(sizeof(struct TreeNode));
	root.left->right->right->val = 7;
	root.left->right->right->left = root.left->right->right->right = NULL;
	root.right = malloc(sizeof(struct TreeNode));
	root.right->val = 3;
	root.right->left = NULL;
	root.right->right = malloc(sizeof(struct TreeNode));
	root.right->right->val = 8;
	root.right->right->left = malloc(sizeof(struct TreeNode));
	root.right->right->left->val = 9;
	root.right->right->left->left = root.right->right->left->right = NULL;
	root.right->right->right = NULL;

	int size = 0;
	int *a = inorderTraversal(&root, &size);
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	free(a);

	return 0;
}
