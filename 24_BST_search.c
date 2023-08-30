#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createnode(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        if (!isBST(root->right))
        {
            return 0;
        }
    }
    else
    {
        return 1;
    }
}
struct Node *bstsearch(struct Node *root, int element)
{
    if (root == NULL)
    {
        printf("element not found \n");
        return NULL;
    }
    else if (root->data == element)
    {
        printf("element found\n");
        return root;
    }
    else if (root->data < element)
    {
        bstsearch(root->right, element);
    }
    else
    {
        bstsearch(root->left, element);
    }
}
struct Node *bstsearchIter(struct Node *root, int element)
{
    while (root != NULL)
    {
        if (root->data == element)
        {
            printf("element found \n");
            return root;
        }

        else if (root->data < element)
        {
            root = root->right;
        }
        else if (root->data > element)
        {
            root = root->left;
        }
        if(root==NULL){
            printf("not found ");
            return NULL;
        }
    }

    printf("element not found\n");
    return NULL;
}
int main()
{
    //      5
    //     / \
    //    2   6
    //   / \
    //  1   4
    struct Node *p1 = createnode(5);
    struct Node *p2 = createnode(2);
    struct Node *p3 = createnode(6);
    struct Node *p4 = createnode(1);
    struct Node *p5 = createnode(9);
    p1->left = p2;
    p2->left = p4;
    p2->right = p5;
    p1->right = p3;
    struct Node *p6 = bstsearchIter(p1, 4);
    printf(" %d ", p6->data);

    return 0;
}
