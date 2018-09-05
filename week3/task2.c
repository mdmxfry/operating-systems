#include <stdio.h>
#include <stdlib.h>

struct LNode {
    int value;
    struct LNode *next;
};

void print_list(struct LNode *node) {
    while (node != NULL) {
        printf(" %d ", node->value);
        node = node->next;
    }
}

void insert_node(struct LNode **head, int new_data) {
    struct LNode *last = *head;
    struct LNode *new_node = (struct LNode *) malloc(sizeof(struct LNode));

    new_node->value = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void delete_node(struct LNode **head, int value){
    struct LNode* prev_node;
    struct LNode* cur_node = *head;

    if(cur_node->value==value){
        *head = cur_node->next;
        free(cur_node);
        return;
    }

    while(cur_node!=NULL && cur_node->value!=value){
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    prev_node->next = cur_node->next;
    free(cur_node);

}

int main() {
    struct LNode *head = NULL;
    insert_node(&head, 5);
    insert_node(&head, 50);
    insert_node(&head, 500);
    print_list(head);
    delete_node(&head, 50);
    print_list(head);
}

