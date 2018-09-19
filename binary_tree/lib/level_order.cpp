/**
 * Return list of level order traversal
 */
#include <list>
#include <queue>

#include "../tree.h"

using std::list;
using std::queue;

list<int> BinaryTree::level_order(void)
{
    list<int> result;
    
    // queue to store node pointers
    queue<binary_tree_node *> q;
    q.push(this->root);

    while (!q.empty())
    {
        binary_tree_node *top = q.front();
        q.pop();

        result.push_back(top->data);

        // left node exists
        if (top->left)
            q.push(top->left);

        // right node exists
        if (top->right)
            q.push(top->right);
    }

    return result;
}