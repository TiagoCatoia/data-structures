#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list* create_list(int size) {
    t_list *list = (t_list *)malloc(sizeof(t_list));
    if (list == NULL) {
        return 0;
    }
    list->max = size;
    list->n = 0;
    list->items = (int *)malloc(sizeof(int) * size);
    if (list->items == NULL) {
        return 0;
    }

    return list;
}

int increase_list(t_list *list) {
    if (is_empty(list)) return 0;
	int size = list->max++;
	list->items = (int *)realloc(list->items, size);
    return 1;
}

int is_full(t_list *list) {
    return list->max == list->n;
}

int is_empty(t_list *list) {
	if (list->n == 0) {
		return 1;
	}
	return 0;
}

int destroy_list(t_list *list) {
    free(list->items);
    free(list);
    return 1;
}

int clear(t_list *list) {
    if (list == NULL) return 0;
    int i;
	for (i = 0; i < list->n; i++) {
		list->items[i] = 0;
		list->n--;
	}
    return 1;
}

int index_of(t_list *list, int elem) {
    int i;
	for (i = 0; i < list->n; i++) {
        if (list->items[i] == elem) {
            return i;
        }
    }
    return -1;
}

int get(t_list *list, int index) {
    if (index > list->n) {
        return -1; // ERROR
    }
    return list->items[index];
}

int count(t_list *list, int elem) {
	int count = 0, i;
	for (i = 0; i < list->n; i++) {
		if (list->items[i] == elem) {
			count++;
		}
	}
	return count;
}

int size(t_list *list) {
	return list->n;
}

int append(t_list *list, int elem) {
    if (is_full(list)) {
        return 0;
    }
    list->items[list->n] = elem;
    list->n++;
    return 1;
}

int insert(t_list *list, int elem, int index) {
    if (is_full(list) || index > list->max || index < list->n) {
        return 0;
    }
	int i;
    for (i=list->n; i >= index; i--) {
        list->items[i+1] = list->items[i];
    }
    list->items[index] = elem;
    list->n++;
    return 1;
}

int update(t_list *list, int elem, int index) {
    if (index > list->max) {
        return 0;
    }
    list->items[index] = elem;
    return 1;
}

int remove_by_index(t_list *list, int index) {
    if (index > list->max) {
        return 0;
    }
	int i;
    for (i=index; i < list->n; i++) {
        list->items[i] = list->items[i+1];
    }
    list->n--;
    return 1;
}

int remove_by_element(t_list *list, int elem) {
    int index = index_of(list, elem);
    if (index == -1) {
        return 0;
    }
    remove_by_index(list, index);
    return 1;
}

int print_list(t_list *list) {
    int i;
	for (i = 0; i < list->n; i++){
        printf("%d\n", list->items[i]);
    }
    return 1;
}