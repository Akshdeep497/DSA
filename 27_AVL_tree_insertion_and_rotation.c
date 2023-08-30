#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int getheight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getBF(struct Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}
struct Node *leftrotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->right), getheight(x->left)) + 1;
    y->height = max(getheight(y->right), getheight(y->left)) + 1;

    return y;
}
struct Node *rightrotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *t1 = x->right;
    x->right = y;
    y->left = t1;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;
    return x;
}
struct Node *insert(struct Node *root, int element)
{
    if (root == NULL)
    {
        return createNode(element);
    }
    if (element < root->key)
    {
        root->left = insert(root->left, element);
    }
    else if (element > root->key)
    {
        root->right = insert(root->right, element);
    }
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    int BF = getBF(root);
    if (BF > 1 && element < root->left->key)
    {
        return rightrotate(root);
    }
    if (BF < -1 && element > root->right->key)
    {
        return leftrotate(root);
    }
    if (BF > 1 && element > root->left->key)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    if (BF < -1 && element < root->right->key)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

struct Node *insert2(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getBF(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}
int main()
{
    struct Node *root = NULL;
    root = insert2(root, 1);
    root = insert2(root, 2);
    root = insert2(root, 4);
    root = insert2(root, 5);
    root = insert2(root, 6);
    root = insert2(root, 3);
    preOrder(root);

    return 0;
}
