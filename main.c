#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* head;

struct node* get (int position) {
    struct node *naavaerende = head;

    for (int i = 0; i < position; ++i) {
        naavaerende = naavaerende->next;
    }
    return naavaerende;
}

void setteInn(int position, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = 0;

    if(position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        struct node *forrige = get(position - 1);
        struct node *naavaerende = forrige->next;

        newNode->next = naavaerende;
        forrige->next = newNode;
    }
    printf("Createt a node\n");
}

void displayOne (int position) {
    struct node *temp = get(position);

    printf("The second of the node has the value %i, and the memory address %p\n", temp->value, &temp);
    free(temp);
}

void displayAll () {
    struct node *current = head;

    while (current != NULL) {
        printf("The second of the node has the value %i, and the memory address %p\n", current->value, &current);

        current = current->next;
    }
    free(current);
}
/*følgende funksjoner må inn her er et sted:
    * void push_back(const int value)
        Add a value to the back of your list
    * size_t size()
        Get the item count
    * int& at(size_t index)
        Retrieve item by index
    * void remove(size_t index)
        Remove item at specified index*/


int main() {
    head = 0;

    setteInn(0, 5);
    setteInn(1, 10);
    setteInn(2, 20);

    displayOne(2);
    displayAll();


    return 0;
}
