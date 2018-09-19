/**
 * Various operations on binary tree
 */

#include <iostream>
#include <list>

#include "tree.h"

using namespace std;

int main(void)
{
    BinaryTree tree;

    list<int> preorder = tree.pre_order();
    for (auto &i : preorder)
        cout << i << " ";
    cout << endl;

    list<int> inorder = tree.in_order();
    for (auto &i : inorder)
        cout << i << " ";
    cout << endl;

    list<int> postorder = tree.post_order();
    for (auto &i : postorder)
        cout << i << " ";
    cout << endl;

    list<int> levelorder = tree.level_order();
    for (auto &i : levelorder)
        cout << i << " ";
    cout << endl;
}