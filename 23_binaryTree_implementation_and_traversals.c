#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int count = 0;
struct Node *createnode(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void prefixtraversal(struct Node *top)
{
    printf("%d ", top->data);
    if (top->left != NULL)
    {
        prefixtraversal(top->left);
    }
    if (top->right != NULL)
    {
        prefixtraversal(top->right);
    }
    count++;
}
void prefixtraversal2(struct Node *top)
{
    count++;
    if (top != NULL)
    {
        printf("%d ", top->data);

        prefixtraversal2(top->left);

        prefixtraversal2(top->right);
    }
}
void postfixtraversal(struct Node *top)
{
    count++;

    if (top->left != NULL)
    {
        postfixtraversal(top->left);
    }
    if (top->right != NULL)
    {
        postfixtraversal(top->right);
    }
    printf("%d ", top->data);
}
void postfixtraversal2(struct Node *top)
{
    count++;
    if (top != NULL)
    {

        postfixtraversal2(top->left);

        postfixtraversal2(top->right);
        printf("%d ", top->data);
    }
}
void infixtraversal(struct Node *top)
{
    count++;
    if (top->left != NULL)
    {
        infixtraversal(top->left);
    }
    if (top != NULL)
    {
        printf("%d ", top->data);
    }
    if (top->right != NULL)
    {
        infixtraversal(top->right);
    }
}
void inOrder(struct Node *root)
{
    count++;
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2
    struct Node *p1 = createnode(4);
    struct Node *p2 = createnode(1);
    struct Node *p3 = createnode(6);
    struct Node *p4 = createnode(5);
    struct Node *p5 = createnode(2);
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    free(p5);
    // prefixtraversal2(p1);
    // infixtraversal(p1);
    // inOrder(p1);
    infixtraversal(p1);

    printf("\ncount is %d\n", count);
    return 0;
}
