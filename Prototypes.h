//
// Created by Vladimir on 1/20/2020.
//

#ifndef COP_3530__ALGORITHMS__PROTOTYPES_H
#define COP_3530__ALGORITHMS__PROTOTYPES_H

//Prototype Functions (gives the compiler a heads up about the upcoming function):
void navigate_list_forward(node **front);

void navigate_list_backwards(node **rear);

void insert_front(node **front, node **rear, std::string data);

void insert_front_p(node **front, node **rear, void *data);

void insert_rear(node **front, node **rear, std::string data);

void insert_rear_p(node **front, node **rear, void *data);

std::string remove_front_i(node **front, node **rear);

void *remove_front_p(pointer_node **front, pointer_node **rear);

std::string remove_rear_i(node **front, node **rear);

void *remove_rear_p(pointer_node **p_front, pointer_node **p_rear);

bool empty(node **front, bool output_text);

void empty_list(node **front, node **rear);

void reverse_list(node **front, node **rear);

std::vector<std::string> read_file(const std::string& file_name, std::vector<std::string> file_vector);

std::vector<std::string> make_alphanumeric(std::vector<std::string> file_vector);

#endif //COP_3530__ALGORITHMS__PROTOTYPES_H
