/**
 * Load tree from here if nothing is passed to constructor
 */

#include "tree.h"

// example tree
BinaryTree::BinaryTree(void)
{
    // this->nodes = 8;

    // this->root = new binary_tree_node(1);

    // this->root->left = new binary_tree_node(2);
    // this->root->right = new binary_tree_node(3);

    // this->root->left->left = new binary_tree_node(4);
    // this->root->left->right = new binary_tree_node(5);

    // this->root->right->left = new binary_tree_node(6);
    // this->root->right->right = new binary_tree_node(7);

    this->nodes = 92;
    this->root = new binary_tree_node(7);

    this->root->left = new binary_tree_node(6);
    this->root->right = new binary_tree_node(12);

    this->root->left->left = new binary_tree_node(5);
    this->root->left->right = new binary_tree_node(3);

    this->root->right->left = new binary_tree_node(8);
    this->root->right->right = new binary_tree_node(91);

    this->root->left->right->left = new binary_tree_node(23);
    this->root->right->left->right = new binary_tree_node(14);
}