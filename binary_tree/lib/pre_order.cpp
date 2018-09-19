/**
 * Return list of pre order traversal
 */

#include <list>
#include <stack>

#include "../tree.h"

using std::list;
using std::stack;

list<int> BinaryTree::pre_order(void)
{
    list<int> result;
    binary_tree_node *ptr = this->root;

    // stack
    stack<binary_tree_node *> s;

    while (!s.empty() || ptr)
    {
        // print middle and move to left
        while (ptr)
        {
            result.push_back(ptr->data);
            s.push(ptr);
            ptr = ptr->left;
        }

        binary_tree_node *top = s.top();
        s.pop();

        // go to right subtree if available
        if (top->right)
            ptr = top->right;
    }

    return result;
}