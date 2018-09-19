/**
 * Return list of left view of tree
 */

#include <list>
#include <queue>

#include "../tree.h"

using std::list;
using std::queue;

list<int> BinaryTree::left_view(void)
{
    list<int> result;

    queue<binary_tree_node *> q;
    q.push(this->root);

    while (!q.empty())
    {
        // first element of current level
        result.push_back(q.front()->data);

        // nodes in current level
        size_t nodes = q.size();

        // remove nodes of current level and push nodes of next level
        while (nodes > 0)
        {
            binary_tree_node *top = q.front();
            q.pop();
            
            if (top->left)
                q.push(top->left);

            if (top->right)
                q.push(top->right);

            nodes--;
        }
    }

    return result;
}