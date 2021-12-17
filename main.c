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
    printf("%i, %i", head->value, head->next);


    return 0;
}
