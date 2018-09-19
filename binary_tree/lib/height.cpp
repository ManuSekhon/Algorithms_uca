/**
 * Return height of binary tree
 */
#include <queue>

#include "../tree.h"

using std::queue;

size_t BinaryTree::height(void)
{
    size_t height = 0;
    
    // queue to store each level
    queue<binary_tree_node *> q;
    q.push(this->root);

    while (!q.empty())
    {
        height++;

        // number of nodes in each level
        size_t nodes = q.size();

        // remove nodes at current level and add nodes of next level
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

    return height;
}