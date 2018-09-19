/**
 * Return list containing inorder traversal
 */

#include <list>
#include <stack>

#include "../tree.h"

using std::list;
using std::stack;

// return list of inorder traversal
list<int> BinaryTree::in_order(void)
{
    list<int> result;
    binary_tree_node *ptr = this->root;
    
    stack<binary_tree_node *> s;

    while (!s.empty() || ptr)
    {
        // reach to end of left
        while (ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }

        // print top node
        binary_tree_node *top = s.top();
        result.push_back(top->data);
        s.pop();

        // go to right subtree if present
        if (top->right)
            ptr = top->right;
    }

    return result;
}