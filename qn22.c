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

void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

void preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lc);
    preorder(root->rc);
}

void postorder(struct node* root) {
    if (root == NULL)
        return;
    postorder(root->lc);
    postorder(root->rc);
    printf("%d ", root->data);
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->lc = deleteNode(root->lc, key);
    else if (key > root->data)
        root->rc = deleteNode(root->rc, key);
    else {
        if (root->lc == NULL) {
            struct node* temp = root->rc;
            free(root);
            return temp;
        } else if (root->rc == NULL) {
            struct node* temp = root->lc;
            free(root);
            return temp;
        }
        struct node* temp = root->rc;
        while (temp && temp->lc != NULL)
            temp = temp->lc;
        root->data = temp->data;
        root->rc = deleteNode(root->rc, temp->data);
    }
    return root;
}

struct node* createTree(struct node* root) {
    int value;
    char choice;
    
    printf("Enter the value of the node: ");
    scanf("%d", &value);
    root = insertNode(root, value);
    
    printf("Do you want to add another node? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        root = createTree(root);
    }
    
    return root;
}

void performOperations(struct node* root) {
    int choice, value;
    
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert a New Node\n");
    printf("2. In-order Traversal\n");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Delete a Node\n");
    printf("6. Exit\n");
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
            printf("In-order traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-order traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-order traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Deletion attempted.\n");
            break;
        case 6:
            printf("Exiting...\n");
            return;
        default:
            printf("Invalid choice! Please try again.\n");
    }
    
    performOperations(root);
}

int main() {
    struct node* root = NULL;
    
    printf("Create the binary search tree:\n");
    root = createTree(root);
    
    performOperations(root);
    
    return 0;
}
