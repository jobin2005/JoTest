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

struct node* createTree() {
    int data, hasLeft, hasRight;
    printf("Enter the value of the node: ");
    scanf("%d", &data);
    struct node* root = createNode(data);
    printf("Does node with value %d have a left child? (1 for yes, 0 for no): ", data);
    scanf("%d", &hasLeft);
    if (hasLeft) {
        root->lc = createTree();
    }
    printf("Does node with value %d have a right child? (1 for yes, 0 for no): ", data);
    scanf("%d", &hasRight);
    if (hasRight) {
        root->rc = createTree();
    }
    return root;
}

void inorder(struct node* temp) {
    if (temp == NULL)
        return;
    inorder(temp->lc);
    printf("%d ", temp->data);
    inorder(temp->rc);
}

void preorder(struct node* temp) {
    if (temp == NULL)
        return;
    printf("%d ", temp->data);
    preorder(temp->lc);
    preorder(temp->rc);
}

void postorder(struct node* temp) {
    if (temp == NULL)
        return;
    postorder(temp->lc);
    postorder(temp->rc);
    printf("%d ", temp->data);
}

struct node* findNode(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    struct node* leftSearch = findNode(root->lc, value);
    if (leftSearch != NULL) {
        return leftSearch;
    }
    return findNode(root->rc, value);
}

void insertNodeAtParent(struct node* root, int parentValue, int data) {
    struct node* parentNode = findNode(root, parentValue);
    if (parentNode == NULL) {
        printf("Parent node with value %d not found.\n", parentValue);
        return;
    }
    if (parentNode->lc == NULL) {
        parentNode->lc = createNode(data);
        printf("Node with value %d inserted as left child of %d.\n", data, parentValue);
    } else if (parentNode->rc == NULL) {
        parentNode->rc = createNode(data);
        printf("Node with value %d inserted as right child of %d.\n", data, parentValue);
    } else {
        printf("Node with value %d has both children, cannot insert new node.\n", parentValue);
    }
}

struct node*  deleteLeafNode(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key) {
        if (root->lc == NULL && root->rc == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Node with value %d is not a leaf node and cannot be deleted.\n", key);
            return root;
        }
    }

    root->lc = deleteLeafNode(root->lc, key);
    root->rc = deleteLeafNode(root->rc, key);
    
    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value, parentValue;

    printf("Create the binary tree:\n");
    root = createTree();

    do {
        printf("\n\nBinary Tree Operations:\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Insert a New Node\n");
        printf("5. Delete a Node (Only Leaf Node)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Pre-order traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the parent node value: ");
                scanf("%d", &parentValue);
                printf("Enter the value of the new node: ");
                scanf("%d", &value);
                insertNodeAtParent(root, parentValue, value);
                break;
            case 5:
                printf("Enter the value to delete (Only leaf nodes can be deleted): ");
                scanf("%d", &value);
               root= deleteLeafNode(root, value);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
