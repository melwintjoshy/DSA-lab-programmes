#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int tree[MAX_SIZE];

// Initialize the tree with -1 (indicating empty nodes)
void initializeTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }
}

// Insert a value into the BST
void insert(int value) {
    int index = 0;
    while (index < MAX_SIZE) {
        if (tree[index] == -1) {
            tree[index] = value;
            return;
        } else if (value < tree[index]) {
            index = 2 * index + 1;
        } else {
            index = 2 * index + 2;
        }
    }
    printf("Tree is full\n");
}

// In-order traversal
void inorderTraversal(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    inorderTraversal(2 * index + 1);
    printf("%d ", tree[index]);
    inorderTraversal(2 * index + 2);
}

int main() {
    initializeTree();
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("In-order traversal: ");
    inorderTraversal(0);
    printf("\n");

    return 0;
}
