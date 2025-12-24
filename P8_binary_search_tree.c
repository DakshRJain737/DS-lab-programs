#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        return NULL;

    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return create(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void display(struct node *root)
{
    printf("\n Elements in Tree: ");
    inorder(root);
    printf("\n");
}

void main()
{
    struct node *root = NULL;
    int n, val;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter the values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\n\n Inorder Traversal: ");
    inorder(root);

    printf("\n\n Preorder Traversal: ");
    preorder(root);

    printf("\n\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nDisplay:\n");
    display(root);
}