//
// Created by Vladimir on 1/20/2020.
//

#ifndef COP_3530__ALGORITHMS__PROTOTYPES_H
#define COP_3530__ALGORITHMS__PROTOTYPES_H

//Prototype Functions (gives the compiler a heads up about the upcoming function):
void insert_front(node **front, node **rear, int data);

void navigate_list_forward(node **front);

void navigate_list_backwards(node **rear);

void insert_rear(node **front, node **rear, int data);

void insert_rear(void *data);

int remove_front_i();

void *remove_front_p();

int remove_rear_i();

void *remove_rear_p();

bool empty(node **front);

#endif //COP_3530__ALGORITHMS__PROTOTYPES_H
