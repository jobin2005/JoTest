#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* lc;
    struct node* rc;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->lc = NULL;
    newNode->rc = NULL;
    return newNode;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->lc = insertNode(root->lc, data);
    } else if (data > root->data) {
        root->rc = insertNode(root->rc, data);
    }
    return root;
}

int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->lc == NULL && root->rc == NULL) {
        return 1;
    }
    return countLeafNodes(root->lc) + countLeafNodes(root->rc);
}

int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a Node\n");
        printf("2. Count Leaf Nodes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
