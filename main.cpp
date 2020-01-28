/**
 * @Author Vladimir Hardy
 */
#include <iostream>
// To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.
struct node {
    int data;
    node* next;
};
bool isNull = true;
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
    //insert_front(&front,&rear,7);
    //insert_front(&front,&rear,10);
    return 0;
}

/**
 * @brief adds a new node to the front of a linked list with data
 * @param front the front pointer
 * @param rear  the rear pointer
 * @param data data that will be held in the node
 */
void insert_front(node **front, node **rear, int data) {

    node *p_data;
    p_data = new node;
    p_data -> data = data;
    std::cout << "Front " << front << std::endl;
    //if(isNull) {
    if(front) { // Special case
        std::cout << "p_data: " << p_data << std::endl;
        *front = *rear = p_data; //does being equal to P_data make front and rear point to p_data or a new node data?
        std::cout << "rear: " << rear << std::endl;
        p_data -> next = nullptr;
    }
    else { // One or more nodes
        std::cout << "One or more nodes " << data << std::endl;
        p_data -> next = *front;
        *front = p_data;
    }

    // General case for adding links

}

void navigate_list() {
    //std::cout << p -> next << std::endl;
}

void insert_front(void *data);

void insert_rear(int data);

void insert_rear(void *data);

int remove_front_i();

void *remove_front_p();

int remove_rear_i();

void *remove_rear_p();

int empty();