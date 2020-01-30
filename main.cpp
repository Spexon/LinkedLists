/**
 * @Author Vladimir Hardy
 */
#include <iostream>
// To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.
struct node {
    int data;
    node* next;
    node* prev;
};
#include "Prototypes.h"

/**
 * @brief calls all linked list functions
 * @definition Linked List: A collection of nodes that together form a linear ordering. Each node stores a pointer,
 * called next, to the next node of the list.
 * @return
 */
int main() {

    node* front = new node;
    node* rear = new node;
    front = rear = nullptr;
    insert_front(&front,&rear,5);
    insert_front(&front,&rear,7);
    insert_front(&front,&rear,10);
    return 0;
}

/**
 * @brief adds a new node to the front of a linked list with data (SO FAR, we can get the front and rear data, but nothing in the middle)
 * @param front the front pointer
 * @param rear  the rear pointer
 * @param data data that will be held in the node
 */
void insert_front(node **front, node **rear, int data) {

    std::cout << "=============\n" << std::endl; //separator
    node *p_data = new node;
    p_data -> data = data;
    //std::cout << "Front " << *front << std::endl; //Proof that front is null at the beginning
    if(*front == nullptr) { // Special case
        std::cout << "p_data: " << p_data << std::endl;
        *front = *rear = p_data; //does being equal to P_data make front and rear point to p_data or a new node data?
        std::cout << "Front: " << front << std::endl;
        //std::cout << "rear: " << rear << std::endl;
        hold = data;
        p_data -> next = nullptr;
        std::cout << "First Data: " << p_data -> data << std::endl;
    }
    else { // One or more nodes (general case)
        p_data -> next = *front; //This moves the link of the new node to the next node
        std::cout << "New front: " << front << std::endl;
        front = &p_data;
        std::cout << "Old front: " << front << std::endl;
        std::cout << "Data: " << p_data -> data << std::endl;
    }
}

void navigate_list() {
    
}

void insert_front(void *data);

void insert_rear(int data);

void insert_rear(void *data);

int remove_front_i();

void *remove_front_p();

int remove_rear_i();

void *remove_rear_p();

int empty();