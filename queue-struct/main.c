#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    t_queue *queue = create_queue(5);
    in(queue, 2);
    in(queue, 3);
    in(queue, 8);
    in(queue, 1);
    in(queue, 9);
    in(queue, 7);
    print_queue(queue);
    printf("Size: %d\n", size(queue));
    t_elem x;
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    in(queue, 2);
    in(queue, 3);
    print_queue(queue);
    out(queue, &x);
    printf("Out value: %d\nSize: %d\n", x, size(queue));
    print_queue(queue);
    clear(queue);
    print_queue(queue);
    destroy_queue(queue);
    return 0;
}
