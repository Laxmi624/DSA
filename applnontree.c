#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node NODE;

// Create node
NODE* createNode(int x) {
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert
NODE* insert(NODE* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Search
void search(NODE* root, int key) {
    if (root == NULL) {
        printf("Element not found\n");
        return;
    }
    if (root->data == key) {
        printf("Element found\n");
        return;
    }
    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

// Find minimum
NODE* findMin(NODE* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete
NODE* deleteNode(NODE* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }

        NODE* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Display (Inorder)
void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main Menu
int main() {
    NODE* root = NULL;
    int choice, x;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1.Insert 2.Search 3.Delete 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &x);
                search(root, x);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 4:
                inorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
