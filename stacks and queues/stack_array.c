#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 20

bool push(int *stack, int *top, int item);
bool pop(int *stack, int *top, int *val);

int main(void)
{
    int stack[MAX_LEN];
    int top = -1;
    int run = 1;
    int menu, val;
    bool succ;
    while (run)
    {
        printf("\nStack: [ ");
        for (int i=0; i<=top; i++)
        {
            printf("|%d| ", stack[i]);
        }
        printf("]\n");

        printf("Operations:\n[1] Push\n[2] Pop\n[3] Exit Program\nEnter command: ");
        scanf("%d", &menu);

        if (menu == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            succ = push(stack, &top, val);
        }
        else if (menu == 2)
        {
            succ = pop(stack, &top, &val);
            if (succ)
            {
                printf("Popped value: %d\n", val);
            }
        }
        else if (menu == 3)
        {
            run = 0;
        }
        else
        {
            printf("Unrecognized input.\n");
        }
    }
    return 0;
}

bool push(int *stack, int *top, int item)
{
    if (*top >= MAX_LEN - 1)
    {
        printf("ERROR: OVERFLOW\n");
        return false;
    }
    else
    {
        *(stack + *top + 1) = item;
        *top = *top + 1;
        return true;
    }
}

bool pop(int *stack, int *top, int *val)
{
    if (*top < 0)
    {
        printf("ERROR: UNDERFLOW\n");
        return false;
    }
    else
    {
        *val = *(stack + *top);
        *top = *top - 1;
        return true;
    }
}
