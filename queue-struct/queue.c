#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

t_queue* create_queue(int capacity) {
    t_queue *p = (t_queue *)malloc(sizeof(t_queue));
    if (p == NULL) return NULL;
    p->items = (t_elem *)malloc(sizeof(t_elem) * capacity);
    if (p->items == NULL) return NULL;
    p->max = capacity;
    p->start = 0;
    p->end = -1;
    p->n = 0;
    return p;
}

int in(t_queue *p, t_elem x) {
    if (is_full(p)) return 0;
    if (p->end + 1 > p->max) {
        p->end = -1;
    }
    p->items[++p->end] = x;
    p->n++;
    return 1;
}

int out(t_queue *p, t_elem *x) {
    if (is_empty(p)) return 0;
    if (p->start + 1 > p->max) {
        *x = p->items[p->start];
        p->start = 0;
    } else *x = p->items[p->start++];
    dequeue(p, p->start - 1);
    return 1;
}

void dequeue(t_queue *p, int remove_index) {
    if (remove_index == p->n) {
        p->n--;
    }
    else {
        int i;
        for (i = remove_index; i < p->n - 1; i++) {
            p->items[i] = p->items[i + 1];
        }
        p->start--;
        p->end--;
        p->n--;
    }
}

int is_full(t_queue *p) {
    if (p->n == p->max) return 1;
    return 0;
}

int is_empty(t_queue *p) {
    if (p->n == 0) return 1;
    return 0;
}

int clear(t_queue *p) {
    if (is_empty(p)) return 0;
    p->start = 0;
    p->end = -1;
    p->n = 0;
    return 1;
}

int size(t_queue *p) {
    if (is_empty(p)) return 0;
    return p->n;
}

int print_queue(t_queue *p) {
    if (is_empty(p)) return 0;
    printf("Queue:");
    int i;
    for (i = 0; i < p->n; i++) {
        printf(" | %d", p->items[i]);
    }
    printf(" |\n");
    return 1;
}

int destroy_queue(t_queue *p) {
    if (p == NULL) return 0;
    free(p->items);
    free(p);
    return 1;
}