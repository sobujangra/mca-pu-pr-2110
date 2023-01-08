// Stack More Practice

#include <stdio.h>
#include <stdlib.h>

struct ArrayStack
{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *createStack(int cap)
{
    struct ArrayStack *stack = malloc(sizeof(struct ArrayStack));

    stack->top = -1;
    stack->capacity = cap;
    stack->array = malloc(sizeof(int) * cap);

    return stack;
}

int isFull(struct ArrayStack *stack)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack is Full - Overflow.");
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct ArrayStack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is Empty - Underflow.");
        return 1;
    }
    else
        return 0;
}

void push(struct ArrayStack *stack)
{
    int item;

    if (!isFull(stack))
    {
        printf("Enter number to push: ");
        scanf("%d", &item);
        stack->array[++stack->top] = item;
    }
}

void pop(struct ArrayStack *stack)
{
    int item;

    if (!isEmpty(stack))
    {
        item = stack->array[stack->top--];
        printf("The popped value is: %d", item);
    }
}

void traverse(struct ArrayStack *stack)
{
    int i = 0;
    if (!isEmpty(stack))
    {
        while (i <= stack->top)
        {
            printf("\nThe value at %d: %d", i, stack->array[i]);
            i++;
        }
    }
}

int main()
{
    int choice;

    struct ArrayStack *stack = createStack(4);

    while (1)
    {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            traverse(stack);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}