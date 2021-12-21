#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int value;
    struct node* next;
};

struct node* head;

struct node* get (int position) {
    struct node *current = head;

    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current;
}

void setteInn(int position, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = 0;

    if(position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node *previous = get(position - 1);
        struct node *current = previous->next;

        newNode->next = current;
        previous->next = newNode;
    }


    printf("Createt a node\n");
}

void displayOne (int position) {
    struct node *temp = get(position);

    printf("The node number %i has the value %i, and the memory address %p\n", position, temp->value, temp);

}

void displayAll () {
    struct node *current = head;
    int curr = 0;

    while (current != NULL) {
        printf("The node number %i has the value %i, and the memory address %p\n", curr, current->value, current);

        current = current->next;
        curr++;
    }
}

void deleteOne (int position) {
    struct node *prev;


    if (position == 0) {
        prev = get(0)->next;
        free(head);
        head = prev;
    } else {
        prev = get(position - 1);
        struct node *toDelete = prev->next;
        prev->next = get(position)->next;
        free(toDelete);
    }

}
int main() {
    head = 0;

    setteInn(0, 5);
    setteInn(1, 10);
    setteInn(2, 20);
    setteInn(3, 600);
    setteInn(0, 800);


    displayAll();

    deleteOne(1);

    displayAll();

    deleteOne(0);

    displayAll();

    return 0;
}