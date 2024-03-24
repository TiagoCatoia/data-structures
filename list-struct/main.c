#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_list *list; 
    list = create_list(5);
    append(list, 11); append(list, 10); append(list, 10); append(list, 10);
    print_list(list);
    printf("\n");
    insert(list, 8, 4);
    print_list(list);
    printf("\n");
    remove_by_index(list, 0);
    print_list(list);
    printf("\n");
    remove_by_element(list, 8);
    print_list(list);
    int num = get(list, 2);
    printf("\n%d\n", num);
    int count_num = count(list, 10);
    printf("\n%d\n", count_num);
    int size_list = size(list);
    printf("\n%d\n", size_list);
    
    
    return 0;
}
