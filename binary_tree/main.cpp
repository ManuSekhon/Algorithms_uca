/**
 * Various operations on binary tree
 */

#include <iostream>
#include <list>

#include "tree.h"

using std::list;

int main(void)
{
    BinaryTree tree;

    // pre order
    list<int> preorder = tree.pre_order();
    printf("Pre Order: ");
    for (auto &i : preorder)
        printf("%d ", i);
    printf("\n");

    // in order
    list<int> inorder = tree.in_order();
    printf("In Order: ");
    for (auto &i : inorder)
        printf("%d ", i);
    printf("\n");

    // post order
    list<int> postorder = tree.post_order();
    printf("Post Order: ");
    for (auto &i : postorder)
        printf("%d ", i);
    printf("\n");

    // level order
    list<int> levelorder = tree.level_order();
    printf("Level Order: ");
    for (auto &i : levelorder)
        printf("%d ", i);
    printf("\n");

    // height of tree
    printf("Height: %zu\n", tree.height());

    // left view
    list<int> leftview = tree.left_view();
    printf("Left view: ");
    for (auto &i : leftview)
        printf("%d ", i);
    printf("\n");

    // right view
    list<int> rightview = tree.right_view();
    printf("Right view: ");
    for (auto &i : rightview)
        printf("%d ", i);
    printf("\n");

    // top view
    list<int> topview = tree.top_view();
    printf("Top view: ");
    for (auto &i : topview)
        printf("%d ", i);
    printf("\n");
}