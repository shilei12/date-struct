/**
 * https://www.jianshu.com/p/bf73c8d50dc2 
 *         树：N个节点的有限集合
 * 1. N = 0; 该树为空树
 * 2. N != 0; 为非空树， 存在两个特点：
 *                       a. 有且有唯一的根节点
 *                       b. 除去根节点外， 其余的节点又可以形成m(m>0)个有限集合， 每个集合本身又是一颗数
 */

/**
 * 二叉树：1. 每个节点的度都不大于2
 *         2. 左右子树是有顺序的 不能颠倒
 * 
 */

/**
 * 满二叉树：1. 除了叶子节点外， 每一个节点的度都是2
 *           2. 叶子节点在同一层
 */

/**
 * 完全二叉树：1. 叶子节点只在最外层和次外层
 *             2. 在完全二叉树中，编号为i的节点和相同深度的满二叉树中编号为i的节点的位置一致
 */

/** 结论1： 满二叉树一定是完全二叉树， 完全二叉树不一定是满二叉树 */

/** 结论2 ：除了完全二叉树采用顺序存储的方式尚可 其他的使用顺序存储都会造成内存浪费 */
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

// binary tree preorder traversal

void PreorderTraversal(Node *tree)
{
    if (tree == nullptr) {
        return;
    }

    int value = tree->val;          // access the node every time 前序遍历
    PreorderTraversal(tree->left);
    PreorderTraversal(tree->right);

}

void InorderTraversal(Node *tree)
{
    if (tree == nullptr) {
        return;
    }

    InorderTraversal(tree->left);
    int value = tree->val;          // access the node every second time 中序遍历
    InorderTraversal(tree->right);

}

void PostorderTraversal(Node *tree)
{
    if (tree == nullptr) {
        return;
    }

    PostorderTraversal(tree->left);
    PostorderTraversal(tree->right);
    int value = tree->val;          // access the node every third time 后序遍历

}

void LevelOrderTraversal(Node *tree)
{
    if (tree == nullptr) {
        return;
    }
    queue<Node *> myQueue;
    myQueue.push(tree);
    while (!myQueue.empty()) {
        size_t size = myQueue.size();
        for (int i = 0; i < size; ++i) {
            Node *innerNode = myQueue.front();
            myQueue.pop();
            if (innerNode->left != nullptr) {
                myQueue.push(innerNode->left);
            }
            if (innerNode->right != nullptr) {
                myQueue.push(innerNode->right);
            }
        }
    }
}