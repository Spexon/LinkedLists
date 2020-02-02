/**
 * @Author Vladimir Hardy
 */
#include <iostream>

// To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.
struct node {

    int data;
    node *next; //This may need to be swapped with prev
    node *prev;

    //friend class double_linked_list;
};

#include "Prototypes.h"

/**
 * @brief calls all linked list functions
 * @definition Linked List: A collection of nodes that together form a linear ordering. Each node stores a pointer,
 * called next, to the next node of the list.
 * @return
 */

int main() {

    node *front = new node;
    node *rear = new node;
    front = rear = nullptr;
    empty(&front);
    insert_rear(&front, &rear, 16);
    insert_rear(&front, &rear, 12);
    insert_front(&front, &rear, 5);
    insert_front(&front, &rear, 7);
    insert_front(&front, &rear, 10);

    remove_front_i(&front, &rear);
    empty(&rear);
    navigate_list_forward(&front);
    navigate_list_backwards(&rear);
    return 0;
}

/**
 * @brief Navigates through a linked list and prints its data starting from the front
 * @param front: a pointer that points to the first node in the list
 */
void navigate_list_forward(node **front) {

    std::cout << "Navigating linked list forwards: " << std::endl;
    node *p_data = new node;
    p_data = *front;
    while (p_data != nullptr) {
        //std::cout << p_data -> next << " " << &rear << std::endl;
        std::cout << p_data->data << std::endl;
        p_data = p_data->next;
    }
}

/**
 * @brief Navigates through a linked list and prints its data starting from the rear
 * @param rear: a pointer that points to the last node in the list
 */
void navigate_list_backwards(node **rear) {

    std::cout << "Navigating linked list backwards: " << std::endl;
    node *p_data;
    p_data = *rear;
    while (p_data != nullptr) {
        std::cout << p_data->data << std::endl;
        p_data = p_data->prev;
    }
}

/**
 * @brief adds a new node to the front of a linked list with data (data gets moved to the left of the most recent node).
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @param data: an integer that will be held in the node
 */
void insert_front(node **front, node **rear, int data) {

    node *p_data = new node;
    p_data->data = data;
    //std::cout << "Front " << *front << std::endl; //Proof that front is null at the beginning
    if (*front == nullptr) { // Special case
        *front = *rear = p_data;
        std::cout << "Front: " << front << std::endl;    //Prints what the variable front is storing
        std::cout << "Front&: " << &front << std::endl;  //Gets the address of &front
        std::cout << "Front*: " << *front << std::endl;  //gets the value *Front is pointing to
        p_data->next = nullptr;
        p_data->prev = nullptr;
    } else { // One or more nodes (general case)
        p_data->next = *front; //This moves the link of the new node to the next node
        (*front)->prev = p_data; //The -> is happening before the *, so the compiler is trying to use -> get_data on a Node<NODETYPE> ** which doesn't work.
        *front = p_data; //The value front is pointing to is assigned p_data
    }
}

/**
 * @brief adds a new node to the end of a linked list (data gets moved to the right of the most recent node).
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @param data: an integer that will be held in the node
 */
void insert_rear(node **front, node **rear, int data) {
    node *p_data = new node;
    p_data -> data = data;
    p_data -> next = nullptr;
    if(*front == nullptr) {
        *front = *rear = p_data;
        p_data->next = p_data->prev = nullptr;
    }
    else {
        p_data->prev = *rear;
        (*rear)->next = p_data;
        *rear = (*rear)->next;
    }
}

/**
 * @brief Removes the front node of a linked list and returns the integer value it stored. pointers pointing to the
 * previous node are deleted
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @return an integer that was stored in the node being deleted
 */
int remove_front_i(node **front, node **rear) {

    node *p_data = new node;

    int hold = 0;
    if(*front == nullptr) {
        std::cout << "Linked List is already empty" << std::endl;
    }
    else if(*front == *rear) {
        hold = (*front)->data;
        p_data = *front;
        delete p_data;
        *front = p_data = nullptr;
    }
    else {
        hold = p_data->data;
        p_data = p_data->next;
        *front = (*front)->next;
        (*front)->prev = nullptr;
        delete p_data->prev;
        delete p_data;
        p_data = nullptr; //Just in case we try to access p_data
    }
    return hold;
}

void *remove_front_p();

int remove_rear_i();

void *remove_rear_p();

/**
 * @brief checks to see if a linked list is empty by using the front pointer
 * @param front: a pointer that points to the first node in a linked list (if it exists)
 * @return true or false, depending on whether the node is empty or not
 */
bool empty(node **front) {

    if(*front == nullptr) { //If the front pointer doesnt point to anything, there isn't data anywhere else
        std::cout << "Linked list is empty" << std::endl;
        return true;
    }
    else {
        std::cout << "Linked list is not empty" << std::endl;
        return false;
    }
}