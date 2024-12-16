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

void inOrderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->lc);
    printf("%d ", root->data);
    inOrderTraversal(root->rc);
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Sorted elements: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
