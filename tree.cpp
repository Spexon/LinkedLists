/**
 * @Author Vladimir Hardy
 */

//#include "tree.h"
#include <iostream>
#include <vector>


struct tree_node {

    std::string data;
    tree_node *Lchild;
    tree_node *Rchild;
    int height; // Every node needs to know height to stay balanced
};

/**
 * AVL tree class for words in file
 */
class tree {

public:
    int node_height(tree_node *T) {
        int returnval = -1;
        if (T != nullptr) {
            returnval = T->height;
        }
        return returnval;
    }

    void insert_tree(tree_node **T, std::string data) {

        if(*T == nullptr) {
            (*T) = new tree_node;
            (*T)->Lchild = (*T)->Rchild = nullptr; // gets new node and attaches
            (*T)->data = data;
            (*T)->height = 0;
        }
        else if (data < (*T)->data ) { // go left
            insert_tree(&(*T)->Lchild,data);
            if ((node_height((*T)->Lchild) - node_height((*T)->Rchild) == 2)) { // Checks if tree is unbalanced
                if (data < (*T)->Rchild->data) {
                    single_rotate_left(T);
                }
                else {
                    double_rotate_left(T);
                }
            }
            else {
                // no balancing needed
                (*T)->height = std::max(node_height((*T)->Lchild), node_height((*T)->Rchild)) + 1;
                std::cout << "Already balanced" << std::endl;
            }

        } // end of 'go left'
        else if (data > (*T)->data) { // go right
            insert_tree(&(*T)->Rchild,data);
            if (node_height((*T)->Rchild) - node_height((*T)->Lchild) == 2) { // Checks if balancing needed
                if ((*T)->Rchild->data < data) {
                    single_rotate_right(T);
                }
                else {
                    double_rotate_right(T);
                }
            }
            else {
                (*T)->height = std::max(node_height((*T)->Lchild), node_height((*T)->Rchild)) + 1;
            }
        } // end of 'go right'
        else {
            // data already in tree, do what you like
        }
    }

    void single_rotate_left(tree_node **T) {
        std::cout << "s_rotate_left" << std::endl;
    }

    void single_rotate_right(tree_node **T) {
        std::cout << "s_rotate_right" << std::endl;
    }

    void double_rotate_left(tree_node **T) {
        std::cout << "d_rotate_left" << std::endl;
    }

    void double_rotate_right(tree_node **T) {
        std::cout << "d_rotate_right" << std::endl;
    }

    void create_AVL_tree(const std::vector<std::string> &file_vector) {


    }
};
