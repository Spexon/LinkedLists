/**
 * @Author Vladimir Hardy
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>

// To access members of a structure, use the dot operator. To access members of a structure through a pointer, use the arrow operator.
struct node {

    std::string data;
    node *next;
    node *prev;
};

struct pointer_node {

    void *data_pointer;
    pointer_node *next;
    pointer_node *prev;
};

#include "Prototypes.h"
#include "tree.cpp"
#include "mapquest.cpp"


/**
 * @brief calls all linked list functions, this is where the test cases are.
 * @definition Linked List: A collection of nodes that together form a linear ordering. Each node stores a pointer,
 * called next, to the next node of the list.
 */
int main() {
    std::vector<std::string> file_vector_for_tree;
    std::vector<std::string> sorted_vector;
    node *front, *rear = new node;
    front = rear = nullptr;
    auto *p_front = new pointer_node; //if you condense this declaration, it messes up addresses (set to 0)
    auto *p_rear = new pointer_node;


    // Homework 2 stuff: Read File
    /*std::string my_file = "test_file.txt";
    read_file(&front, &rear, my_file);
    make_alphanumeric(&front, &rear);
    navigate_list_backwards(&rear);

    //create AVL tree from the words
    tree AVL_tree;
    tree_node *root = nullptr;
    for(std::string i : file_vector_for_tree) { // Trying to call the AVL insert tree for each index in the vector

        //AVL_tree.insert_tree(&root,i); // Causes weird errors where I cannot run the program, accessing something i have no control over, when I edit the test_file?
        //It seems that the 1 height nodes are being replaced with new data instead of percolating up (occurs when given this error in degubber: -var-create: unable to create variable object)
    }*/

    // Homework 3 stuff:
    map_quest mq;
    int test_array[] = {30, 29, 11, 38, 42, 19, 8};
    mq.merge_sort(test_array, 7);
    read_file(&front, &rear, "mapcampus.txt");
    navigate_list_forward(&rear);
}

/**
 * @brief Navigates through a linked list and prints its data starting from the front
 * @param front: a pointer that points to the first node in the list
 */
void navigate_list_forward(node **front) {

    std::cout << "Navigating linked list forwards: " << std::endl;
    if (empty(front, false)) {
        std::cout << "---" << std::endl;
    } else {
        node *p_data = new node;
        p_data = *front;
        while (p_data != nullptr) {
            std::cout << p_data->data << std::endl;
            p_data = p_data->next;
        }
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

int get_list_size(node **front) {
    node *p_data = new node;
    p_data = *front;
    int size = 0;
    while (p_data != nullptr) {
        p_data = p_data->next;
        size++;
    }
    return size;
}

/**
 * @brief adds a new node to the front of a linked list with data (data gets moved to the left of the most recent node).
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @param data: an integer that will be held in the node
 */
void insert_front(node **front, node **rear, std::string data) {

    node *p_data = new node;
    p_data->data = data;
    //std::cout << "Front " << *front << std::endl; //Proof that front is null at the beginning
    if (*front == nullptr) { // Special case
        *front = *rear = p_data;
        //std::cout << "Front: " << front << std::endl;    //Prints what the variable front is storing
        //std::cout << "Front&: " << &front << std::endl;  //Gets the address of &front
        //std::cout << "Front*: " << *front << std::endl;  //gets the value *Front is pointing to
        p_data->next = nullptr;
        p_data->prev = nullptr;
    } else { // One or more nodes (general case)
        p_data->next = *front; //This moves the link of the new node to the next node
        (*front)->prev = p_data; //The -> is happening before the *, so the compiler is trying to use -> get_data on a Node<NODETYPE> ** which doesn't work.
        *front = p_data; //The value front is pointing to is assigned p_data
    }
}

void insert_front_p(pointer_node **p_front, pointer_node **p_rear, void *void_data) {

    pointer_node *p_data;
    p_data->data_pointer = void_data;
    if (*p_front == nullptr) {
        *p_front = *p_rear = p_data;
        p_data->next = nullptr;
        p_data->prev = nullptr;
    } else {
        p_data->next = *p_front;
        (*p_front)->prev = p_data;
        *p_front = p_data;
    }
}

/**
 * @brief adds a new node to the end of a linked list (data gets moved to the right of the most recent node).
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @param data: an integer that will be held in the node
 */
void insert_rear(node **front, node **rear, std::string data) {
    node *p_data = new node;
    p_data->data = data;
    p_data->next = nullptr;
    if (*front == nullptr) {
        *front = *rear = p_data;
        p_data->next = p_data->prev = nullptr;
    } else {
        p_data->prev = *rear;
        (*rear)->next = p_data;
        *rear = (*rear)->next;
    }
}

void insert_rear_p(pointer_node **p_front, pointer_node **p_rear, void *void_data) {


}

/**
 * @brief Removes the front node of a linked list and returns the integer value it stored. pointers pointing to the
 * previous node are deleted
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @return an integer that was stored in the node being deleted
 */
std::string remove_front_i(node **front, node **rear) {

    node *p_data = new node;
    std::string hold = "";
    if (*front == nullptr) {
        std::cout << "Linked List is already empty" << std::endl;
    } else if (*front == *rear) {
        hold = (*front)->data; //not p_data->data because it gives garbage
        p_data = *front;
        delete p_data;
        *front = p_data = nullptr;
    } else {
        hold = (*front)->data;
        *front = (*front)->next;
        (*front)->prev = nullptr;
        p_data = nullptr; //Just in case we try to access p_data
        //delete p_data->prev;
        delete p_data;
    }
    return hold;
}

/**
 * @brief Removes the front address of data that a pointer points to A void* does not mean anything. It is a pointer, but the type that it points to is not known.
 * @param p_front: a pointer that points to the first node in the list
 * @param p_rear:  a pointer that points to the last node in the list
 * @return It returns a pointer to storage that contains an object of a known type
 */
void *remove_front_p(pointer_node **p_front, pointer_node **p_rear) {

    pointer_node *p_data;
    void *void_data = nullptr;
    if (*p_front == nullptr) {
        std::cout << "Linked List is already empty" << std::endl;
    } else if (*p_front == *p_rear) {
        void_data = (*p_front)->data_pointer; //not p_data->data because it gives garbage
        p_data = *p_front;
        delete p_data;
        *p_front = p_data = nullptr;
    } else {
        void_data = (*p_front)->data_pointer;
        *p_front = (*p_front)->next;
        //delete (*p_front)->prev;
        //(*p_front)->prev = nullptr;
    }
    return void_data;
}

/**
 * @brief Removes the last node in the linked list and returns its integer value. pointers pointing to the next node
 * are deleted and set to null
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 * @return An integer that was stored in the node being deleted
 */
std::string remove_rear_i(node **front, node **rear) {

    std::string hold = "";
    node *p_data = new node;
    if (*front == nullptr) {
        std::cout << "Empty linked list" << std::endl;
    } else if (*front == *rear) {
        hold = (*rear)->data;
        delete p_data;
        *front = *rear = nullptr;
    } else {
        hold = (*rear)->data;
        *rear = (*rear)->prev;
        delete (*rear)->next;
        (*rear)->next = nullptr;
        //size--;
    }
    return hold;
}

/**
 * @brief Removes the rear address a pointer points to
 * @param p_front: a pointer that points to the first node in the list
 * @param p_rear:  a pointer that points to the last node in the list
 * @return It returns a pointer to storage that contains an object of a known type
 */
void *remove_rear_p(pointer_node **p_front, pointer_node **p_rear) {

    pointer_node *p_data;
    void *void_data = nullptr;
    if (*p_front == nullptr) {
        std::cout << "Linked List is already empty" << std::endl;
    } else if (*p_front == *p_rear) {
        void_data = (*p_rear)->data_pointer; //not p_data->data because it gives garbage
        p_data = *p_rear;
        delete p_data;
        *p_front = p_data = nullptr;
    } else {
        void_data = (*p_rear)->data_pointer;
        *p_front = (*p_rear)->prev;
        delete (*p_rear)->next;
        (*p_rear)->next = nullptr;
    }
    return void_data;
}

/**
 * @brief checks to see if a linked list is empty by using the front pointer
 * @param front: a pointer that points to the first node in a linked list (if it exists)
 * @return true or false, depending on whether the node is empty or not
 */
bool empty(node **front, bool output_text) {

    if (*front == nullptr) { //If the front pointer doesnt point to anything, there isn't data anywhere else
        if (output_text) {
            std::cout << "Linked list is empty" << std::endl;
        }
        return true;
    } else {
        if (output_text) {
            std::cout << "Linked list is not empty" << std::endl;
        }
        return false;
    }
}

/**
 * @brief Removes all nodes in a linked list
 * @param front: a pointer that points to the first node in the list
 * @param rear:  a pointer that points to the last node in the list
 */
void empty_the_list(node **front, node **rear) {

    while (*front != nullptr) {
        std::cout << remove_front_i(front, rear) << std::endl; //Test case 2: no elements
    }
    //std::cout << "cleared"  << std::endl; //Test case 2: no elements
}

/**
 * @brief supposed to reverse the order of a list, but only prints 1 value
 * @param front
 * @param rear
 */
void reverse_list(node **front, node **rear) {
    node *p_data, *q_data, *r_data = new node;
    p_data = *front;
    q_data = p_data->next;
    r_data = q_data->next;
    (*front)->next = nullptr;
    while(q_data->next != nullptr) {
        q_data->next = p_data;
        p_data = q_data, q_data = r_data, r_data = r_data->next;
    }
    std::cout << "List reversed" << std::endl;
}


void read_file(node **front, node **rear, const std::string& file_name) {
    std::ifstream file_to_be_read; //REMEMBER: Files are stored in cmake-build-debug
    file_to_be_read.open(file_name, std::ios_base::app);
    if(file_to_be_read.is_open()) {
        std::string line;
        while (std::getline(file_to_be_read,line)) { // fixes the issue where \n would be read
            std::stringstream ss(line);
            while (std::getline(ss, line, ' ')) {
                insert_front(front, rear, line);
            }
        }
    }
    else {
        std::cout << "Unable to open file " << file_name << std::endl;
    }
    file_to_be_read.close();
}

void make_alphanumeric(node **front, node **rear) { //bubble sort
    node *p_data = new node;
    std::string temp_val;
    bool unsorted = true;
    p_data = *rear;
    while (unsorted) {
        int swaps = 0;
        while (p_data != *front) {
            if (p_data->data /* d */ > p_data->prev->data /* a */) {
                temp_val = p_data->data; //d
                p_data->data = p_data->prev->data;
                p_data->prev->data = temp_val;
                swaps++;
            }
            if (p_data->prev == nullptr) {
                break;
            }
            p_data = p_data->prev;
        }
        if(swaps == 0) {
            unsorted = false;
        }
    }
}