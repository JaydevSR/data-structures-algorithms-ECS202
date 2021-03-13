#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    int info;
    struct node *next;
}

struct node *linkarr(struct node *, int);
void insertll(struct node **, struct node **, struct node *, int);
struct node *searchll(struct node *, int);
int deletell(struct node **, struct node **, struct node *);
void flushll(struct node **, struct node **)

int main(void)
{
    struct node arr[MAX_NODES];
    struct node *avail = linkarr(arr, MAX_NODES);
    struct node *start = NULL;

    char ch;
    while ((ch = getchar()) != \n)
    {
        insertll(&start, &avail, NULL, (int) ch);
    }
    printll(start);

    return 0;
}

/*
 * Links an array of nodes to form a linked list of available nodes
 */
struct node *linkarr(struct node *arr, int max_len)
{
    for (int i = 0; i < max_len; i++)
    {
        (arr + i) -> next = (arr + i + 1);
    }
    arr + max_len -> next = NULL;
    return arr;
}

/*
 * Traversal: Print the linked list
 */
void printll(struct node *start)
{
    for (struct node *p = start; p -> next != NULL; p = p -> next)
    {
        printf("%d -> ", p -> info);
    }
    printf("NULL\n");
}

/*
 * Insertion: Insert into array after the given location.
 */
void insertll(struct node **start, struct node **avail, struct node *loc, int item)
{
    if (*avail == NULL) // Empty avail
    {
        printf("ERROR: Overflow. No more available nodes to insert.");
    }
    else
    {
        newn = *avail;
        newn -> info = item;
        *avail = *avail -> next;
        if (loc == NULL)
        {
            newn -> next = *start;
            *start = newn;
        }
        else
        {
            newn -> next = loc -> next;
            loc -> next = newn;
        }
    }
}

/*
 * Searching (Linear): Search the linked list for a given item
 */
struct node *searchll(struct node *start, int item)
{
    struct node *loc = *start;
    if (start == NULL)
    {
        printf("No nodes in the linked list!");
    }
    for(loc; loc != NULL; loc = loc -> next)
    {
        if (loc -> info == item)
        {
            break;
        }
    }
    return loc; // NULL if not found
}

/*
 * Deletion: Delete the node from given location
 */
int deletell(struct node **start, struct node **avail, struct node *loc)
{
    int item;
    if (loc == *start)
    {
        struct node *temp = *start;
        *start = *start -> next;
        temp -> next = *avail;
        *avail = temp;
        item = temp -> info;
    }
    else if (loc == NULL) {} // Do nothing!
    else
    {
        struct node *prev;
        for (prev = *start; prev -> next != loc; prev = prev -> next);
        prev -> next = loc -> next;
        loc -> next = *avail;
        *avil = loc;
        item = loc -> info;
    }
    return item;
}

/*
 * Flush the given linked list
 */
void flushll(struct node **start, struct node **avail)
{
    if (*start != NULL) // If not empty already
    {
        struct node *curr;
        for (curr = *start; c -> next != NULL; curr = curr -> next);
        curr -> next = *avail;
        *avail = *start;
        *start = NULL;
    }
}