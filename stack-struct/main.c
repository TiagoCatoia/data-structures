#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_stack *stack = create_stack(5);
    push(stack, 2);
    push(stack, 5);
    push(stack, 10);
    push(stack, 8);
    push(stack, 6);
    push(stack, 3);
    print_stack(stack);
    int full = is_full(stack);
    int empty = is_empty(stack);
    printf("Full: %d\n", full);
    printf("Empty: %d\n", empty);
    t_elem x1;
    printf("Before Pop: %d\n", size(stack));
    pop(stack, &x1);
    printf("After Pop: %d\n", size(stack));
    printf("Value Pop: %d\n", x1);
    print_stack(stack);
    t_elem x2;
    top(stack, &x2);
    printf("Top: %d\n", x2);
    clear(stack);
    int Size = size(stack);
    printf("Size: %d\n", Size);
    destroy_stack(stack);

    return 0;
}