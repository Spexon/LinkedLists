/**
 * @Author Vladimir Hardy
 */
#include <iostream>
// To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.
struct node {
    int data;
    node* next;
};

#include "Prototypes.h"

/**
 * @brief calls all linked list functions
 * @definition Linked List: A collection of nodes that together form a linear ordering. Each node stores a pointer,
 * called next, to the next node of the list.
 * @return
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    node* front = new node;
    node* rear = new node;
    front = rear = nullptr;
    insert_front(&front,&rear,5);
    insert_front(&front,&rear,7);
    insert_front(&front,&rear,10);
    return 0;
}

void insert_front(node **front, node **rear, int data) {

    node *p;
    p = new node;
    p -> data = data;
    if(front == nullptr) {
        std::cout << "Null pointer" << std::endl;
        *front = *rear = p;
        p -> next = nullptr;
    }
    else { // One or more nodes
        std::cout << "One Node or more" << std::endl;
        p -> next = *front;
        *front = p;
    }
}

void navigate_list() {
    std::cout << p -> next << std::endl;
}

void insert_front(void *data);

void insert_rear(int data);

void insert_rear(void *data);

int remove_front_i();

void *remove_front_p();

int remove_rear_i();

void *remove_rear_p();

int empty();