#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int info;
    struct node *left;
    struct node *right;
} NODE;

bool tree_empty(NODE *);
bool insert_bst(NODE **, int);
NODE *search_bst(NODE *, int);

int main(void)
{
    NODE *root = NULL;
    insert_bst(&root, 10);
    printf("%d\n", search_bst(root,10) -> info);
    insert_bst(&root, 10);
    return 0;
}


bool tree_empty(NODE *root)
{
    return (root == NULL);
}


bool insert_bst(NODE **root, int item)
{
    NODE *new = malloc(sizeof(NODE));
    new -> info = item;
    new -> left = NULL;
    new -> right = NULL;

    if(tree_empty(*root))
    {
        *root = new;
        return true;
    }
    else
    {
        NODE *ptr = *root;
        while (true)
        {
            if (item < (ptr -> info))
            {
                if (ptr -> left == NULL)
                {
                    ptr -> left = new;
                }
                else
                {
                    ptr = ptr -> left;
                }
            }
            else if (item > (ptr -> info))
            {
                if (ptr -> left == NULL)
                {
                    ptr -> right = new;
                }
                else
                {
                    ptr = ptr -> right;
                }
            }
            else
            {
                printf("Item already in the BST");
                free(new);
                return false;
            }
        }
        return true;
    }
}


NODE *search_bst(NODE *root, int item)
{
    NODE *ptr = root;

    while (ptr != NULL)
    {
        if (ptr -> info < item)
        {
            ptr = ptr -> left;
        }
        else if (ptr -> info > item)
        {
            ptr = ptr -> right;
        }
        else
        {
            break;
        }
    }

    return ptr;
}


/*
   void print_bst(NODE *root)
   {
   int level = 0;
   NODE *ptr = root;

   }
   */

