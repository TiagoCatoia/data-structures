#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int n;
    int *items;
} t_list;

t_list* create_list(int size);
int increase_list(t_list *list);
int is_full(t_list *list);
int is_empty(t_list *list);
int destroy_list(t_list *list);
int clear(t_list *list);
int index_of(t_list *list, int elem);
int get(t_list *list, int index);
int count(t_list *list, int elem);
int size(t_list *list);
int append(t_list *list, int elem);
int insert(t_list *list, int elem, int index);
int update(t_list *list, int elem, int index);
int remove_by_index(t_list *list, int index);
int remove_by_element(t_list *list, int elem);
int print_list(t_list *list);

#endif
