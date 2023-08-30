#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
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
struct node *bstsearch(struct node *root, int element)
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
struct node *bstsearchIter(struct node *root, int element)
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
        if (root == NULL)
        {
            printf("not found ");
            return NULL;
        }
    }

    printf("element not found\n");
    return NULL;
}
void infixtraversal(struct node *top)
{
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
void insertbst(struct node *root, int key)
{
    struct node *prev = NULL;

    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("cannot insert %d, already in BST", key);
            return;
        }

        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
void insertmine(struct node *root, int key)
{

    struct node *new = createnode(key);
    while (root != NULL)
    {

        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            free(new);
            return;
        }
        else if (key < root->data)
        {
            if (root->left == NULL)
            {
                root->left = new;
                return;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = new;
                return;
            }
            else
            {
                root = root->right;
            }
        }
    }
}

int main()
{
    //      5
    //     / \
    //    2   6
    //   / \
    //  1   4
    struct node *p1 = createnode(5);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(6);
    struct node *p4 = createnode(1);
    struct node *p5 = createnode(4);
    p1->left = p2;
    p2->left = p4;
    p2->right = p5;
    p1->right = p3;

    infixtraversal(p1);
    // struct node * ptr2=createnode(1);
    // ptr2=ptr2->right;
    // struct node * ptr1=createnode(2);
    // if(ptr2==NULL){
    //     printf("null h bhai");
    // }
    // ptr2=ptr1;
    // printf("\n %d",ptr2->data);

    return 0;
}
