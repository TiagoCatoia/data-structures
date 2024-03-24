#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

t_stack* create_stack(int n) {
    t_stack *p = (t_stack *)malloc(sizeof(t_stack));
    p->max = n;
    p->top_index = -1;
    p->items = (t_elem *)malloc(sizeof(t_elem) * n);
    return p;
}

int destroy_stack(t_stack *p) {
    if (p == NULL) return 0;
    free(p->items);
    free(p);
    return 1;
}

int is_full(t_stack *p) {
    return p->top_index == p->max - 1;
}

int is_empty(t_stack *p) {
    return p->top_index == -1;
}

int push(t_stack *p, t_elem x) {
    if (is_full(p)) return 0;
    p->items[++p->top_index] = x;
    return 1;
}

int print_stack(t_stack *p) {
    if (is_empty(p)) return 0;
    int i;
    printf("Stack: \n");
    for (i = 0; i <= p->top_index; i++) {
        printf("%d\n", p->items[i]);
    }
    return 1;
}

void clear(t_stack *p) {
    p->top_index = -1;
}

int pop(t_stack *p, t_elem *x) {
	if (is_empty(p)) return 0;
	*x = p->items[p->top_index--];
    return 1;
}

int size(t_stack *p) {
    if (is_empty(p)) return 0;
    return p->top_index + 1;
}

int top(t_stack *p, t_elem *x) {
	if (is_empty(p)) return 0;
	*x = p->items[p->top_index];
    return 1;
}
