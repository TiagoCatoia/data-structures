#ifndef STACK_H
#define STACK_H

typedef int t_elem;

typedef struct {
    int max;
    int top_index;
    t_elem *items;
} t_stack;

t_stack* create_stack(int n);
int destroy_stack(t_stack *p);
int is_full(t_stack *p);
int is_empty(t_stack *p);
int push(t_stack *p, t_elem x);
int print_stack(t_stack *p);
void clear(t_stack *p);
int pop(t_stack *p, t_elem *x);
int size(t_stack *p);
int top(t_stack *p, t_elem *x);

#endif
