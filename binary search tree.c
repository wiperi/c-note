/**
 * 实现一个简单的二叉搜索树
 * 
 * 利用递归的思想，编写函数，实现以下操作：查找，插入，删除。
 * 
 * 利用查找函数，实现：给定一个整数列表，将该列表转化为一个二叉搜索树
 * 
 * 尝试使用递归的方法优化二叉搜索树，得到一个平衡二叉树
*/
#include <stdio.h>
#include <stdlib.h>

// define the structure of the tree
struct tree {
    int value;
    struct tree* left;
    struct tree* right;
};

// create the root
struct tree* createRoot(int value) {
    struct tree* root = (struct tree*) malloc(sizeof(struct tree));

    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// search for a node
struct tree* searchNode(struct tree* root, int target) {
    if (!root) {
        return NULL;
    }
    
    if (target == root->value) {
        return root;
    } else if (target > root->value) {
        searchNode(root->right, target);
    } else {
        // if (target < root->value) 
        searchNode(root->left, target);
    }
}

// add a node
struct tree* addNode(struct tree* root, int value) { 
    if (root->value == value) {
        return NULL;
    }

    if (value > root->value) {
        if (root->right == NULL) {
            
            // create a new node
            root->right = (struct tree*) malloc(sizeof(struct tree));
            root->right->value = value;
            root->right->left = NULL;
            root->right->right = NULL;

            return root->right;
        } else {
            // if (root->right != NULL)
            addNode(root->right, value);
        }
    } else {
        // if (value < root->value)
         if (root->left == NULL) {
            
            // create a new node
            root->left = (struct tree*) malloc(sizeof(struct tree));
            root->left->value = value;
            root->left->left = NULL;
            root->left->right = NULL;
            
            return root->left;
        } else {
            // if (root->left != NULL)
            addNode(root->left, value);
        }
    }
}

// print the tree
void printTree(struct tree* root) {
    printf("%d ", root->value);
    printf("%p ", root->left);
    printf("%p \n", root->right);

    if (root->left) {
        printTree(root->left);
    }
    if (root->right) {
        printTree(root->right);
    }

    return;
}

int main(void) {
    struct tree* root = createRoot(233);

    addNode(root, 234);
    addNode(root, 235);
    printTree(root);
}