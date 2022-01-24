/*
 * Chapter 10 Challenge 1
 *
 * Create a linked list that holds the numbers from 1 to 100. Then, print every
 * node in your list.
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode {
    int64_t value;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
} LinkedList;

void append_node(LinkedList *list, int64_t value) {
    LinkedListNode *last_node = list->head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    LinkedListNode *new_node = (LinkedListNode*)calloc(1, sizeof(struct LinkedListNode));
    new_node->value = value;
    new_node->next = NULL;
    last_node->next = new_node;
}

void print_list(LinkedList *list) {
    if (list->head->next == NULL) {
        printf("Linked list is empty!\n");
        return ;
    }
    LinkedListNode *current_node = list->head->next;
    do {
        printf("%ld\n", current_node->value);
        current_node = current_node->next;
    } while (current_node != NULL);
}

int main(void) {
    LinkedList *list = (LinkedList*)calloc(1, sizeof(LinkedList));
    LinkedListNode *head_node = (LinkedListNode*)calloc(1, sizeof(LinkedListNode));
    head_node->value = 0;
    head_node->next = NULL;
    list->head = head_node;
    for (size_t i = 1; i != 101; ++i) {
         append_node(list, i);
    }
    print_list(list);

    return 0;
}
