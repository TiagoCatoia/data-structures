#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int t_elem;

typedef struct {
    int max, start, end, n;
    t_elem *items;
} t_queue;

t_queue* create_queue(int capacity);
int in(t_queue *p, t_elem x);
int out(t_queue *p, t_elem *x);
void dequeue(t_queue *p, int remove_index);
int is_full(t_queue *p);
int is_empty(t_queue *p);
int clear(t_queue *p);
int size(t_queue *p);
int print_queue(t_queue *p);
int destroy_queue(t_queue *p);

#endif
