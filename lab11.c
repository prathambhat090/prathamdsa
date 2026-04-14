#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* find_lca(struct TreeNode* root, int n1, int n2) {
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct TreeNode* left = find_lca(root->left, n1, n2);
    struct TreeNode* right = find_lca(root->right, n1, n2);

    if(left && right)
        return root;

    return left ? left : right;
}