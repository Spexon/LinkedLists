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

int node_height(tree_node *T);
void insert_tree(tree_node **T, const std::string& data);
void single_rotate_left(tree_node **T);
void single_rotate_right(tree_node **T);
void double_rotate_left(tree_node **T);
void double_rotate_right(tree_node **T);
void hex_to_decimal(std::string hex);


/**
 * AVL tree class for words in file
 */
class tree {

public:
    int node_height(tree_node *T) {
        int returnval = -1; // Allows math to work nicely for rotates
        if (T != nullptr) {
            returnval = T->height;
        }
        return returnval;
    }

    void insert_tree(std::string& data) {
        tree_node *root;
        root = reinterpret_cast<tree_node *>(&data);
        insert_tree(&root,data);
    }

    void insert_tree(tree_node **T, const std::string& data) {

        if(*T == nullptr) {
            std::cout << "null pointer" << std::endl;
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
        tree_node *k1, *k2;
        k2 = *T;
        k1 = (*T)->Lchild;
        k2->Lchild = k1->Rchild; // This confuses me, line below makes sense
        //k2 = k1->Rchild;
        *T = k1;
        // Fix height
        k2->height = std::max(node_height(k2->Lchild),node_height(k2->Rchild))+1;
        k1->height = std::max(node_height(k1->Lchild),node_height(k1->Rchild))+1;
    }

    void single_rotate_right(tree_node **T) {
        std::cout << "s_rotate_right" << std::endl;
        tree_node *k1, *k2;
        k2 = *T;
        k1 = k2->Rchild;
        k2->Rchild = k1->Lchild;
        *T = k1;
        // Fix height
        k2->height = std::max(node_height(k2->Lchild),node_height(k2->Rchild))+1; // not sure if this works
        k1->height = std::max(node_height(k1->Lchild),node_height(k1->Rchild))+1;
    }

    void double_rotate_left(tree_node **T) {
        std::cout << "d_rotate_left" << std::endl;
        single_rotate_right(&((*T)->Lchild));
        single_rotate_left(T);
        // No need to adjust height since functions already do it
    }

    void double_rotate_right(tree_node **T) {
        std::cout << "d_rotate_right" << std::endl;
        single_rotate_left(&((*T)->Rchild));
        single_rotate_right(T);
        // No need to adjust height since functions already do it
    }

    void create_AVL_tree(const std::vector<std::string> &file_vector) {

        tree_node *root = nullptr;
        try {
            for (std::string i : file_vector) {
                insert_tree(&root, i); // Must be running as administrator
                std::cout << "here: " << root << std::endl;
            }
        }
        catch (tree_node *root) {
            std::cout << "Error: " << root << std::endl;
        }

    }

    void hex_to_decimal(std::string hex) {

        for(int i = 0; i < hex.length(); i++) {
            switch(hex[i]) {
                case 'a':
                    std::cout << hex[i] << std::endl;
                    break;

            }
        }
    }
};
