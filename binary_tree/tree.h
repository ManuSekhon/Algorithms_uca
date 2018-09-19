/**
 * Manuinder Sekhon
 * Binary tree and its operations
 */
#include <iostream>
#include <list>

// Binary tree node containing integer values
struct binary_tree_node
{
    int data;
    binary_tree_node *left;
    binary_tree_node *right;

    binary_tree_node(int data) : data(data), left(NULL), right(NULL) {}
};

/**
 * Various operations on binary tree
 */
class BinaryTree
{
    private:
        // root of tree
        binary_tree_node *root = NULL;

        // number of nodes
        int nodes = 0;

    public:
        // construct tree (defined in load_tree.cpp)
        BinaryTree(void);

        // return list of inorder traversal
        std::list<int> in_order(void);

        // return list of level order traversal
        std::list<int> level_order(void);

        // return list of pre order traversal
        std::list<int> pre_order(void);

        // return list of post order traversal
        std::list<int> post_order(void);
};