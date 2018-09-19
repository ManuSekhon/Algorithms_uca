/**
 * Return list of post order traversal
 */

#include <list>
#include <stack>

#include "../tree.h"

using std::list;
using std::stack;

list<int> BinaryTree::post_order(void)
{
    list<int> result;
    binary_tree_node *ptr = this->root;
    
    stack<binary_tree_node *> s;

    // check if right node is already visited
    bool explored[this->nodes];
    for (bool &i : explored)
        i = false;

    while (!s.empty() || ptr)
    {
        // reach to end of left
        while (ptr)
        {
            s.push(ptr);
            ptr = ptr->left;
        }

        // go to right if available and not visited
        if (s.top()->right)
        {
            if (!explored[s.top()->right->data])
            {
                explored[s.top()->right->data] = true;
                ptr = s.top()->right;
                continue;
            }
        }

        result.push_back(s.top()->data);
        s.pop();
    }

    return result;
}