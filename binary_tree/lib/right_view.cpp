/**
 * Return list of right view of tree
 */

#include <list>
#include <queue>

#include "../tree.h"

using std::list;
using std::queue;

list<int> BinaryTree::right_view(void)
{
    list<int> result;

    queue<binary_tree_node *> q;
    q.push(this->root);

    while (!q.empty())
    {
        // last node of current level
        result.push_back(q.back()->data);

        // number of nodes in current level
        size_t nodes = q.size();

        // remove nodes of current level and add nodes of next level
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