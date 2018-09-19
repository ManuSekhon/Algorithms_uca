/**
 * Return list of top view of binary tree
 */

#include <climits>
#include <list>
#include <queue>

#include "../tree.h"

using std::list;
using std::queue;
using std::pair;
using std::make_pair;

list<int> BinaryTree::top_view(void)
{
    list<int> result;

    // store max rank of left and right sides
    // left rank in +ve value and right rank in -ve value
    int left_rank = 0, right_rank = 0;

    // queue to store node and its rank
    queue<pair<binary_tree_node *, int>> q;
    q.push(make_pair(this->root, 0));

    result.push_back(q.front().first->data);
    
    while (!q.empty())
    {
        // remove current node
        binary_tree_node *top = q.front().first;
        int curr_rank = q.front().second;

        q.pop();

        if (top->left)
        {
            q.push(make_pair(top->left, curr_rank + 1));

            // contribute in top view
            if (curr_rank + 1 > left_rank)
            {
                result.push_front(top->left->data);
                left_rank = curr_rank + 1;
            }
        }

        if (top->right)
        {
            q.push(make_pair(top->right, curr_rank - 1));

            // contribute in top view
            if (curr_rank - 1 < right_rank)
            {
                result.push_back(top->right->data);
                right_rank = curr_rank - 1;
            }
        }
    }

    return result;
}