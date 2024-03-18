#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* left;
    int data;
    struct node* right;
};
struct node* root = NULL;
void insert(struct node* temp, struct node* newnode) {
    if (newnode->data < temp->data) {
        if (temp->left == NULL)
            temp->left = newnode;
        else
            insert(temp->left, newnode);
    }
    else if (newnode->data > temp->data) {
        if (temp->right == NULL)
            temp->right = newnode;
        else
            insert(temp->right, newnode);
    }
}
void insertNode() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        root = newnode;
        printf("Root inserted\n");
    }
    else {
        insert(root, newnode);
        printf("Node inserted\n");
    }
}
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}




void preorder(struct node* temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}
void postorder(struct node* temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void search(struct node* temp, int key) {
    if (temp == NULL) {
        printf("Key element is not found in the BST\n");
        return;
    }

    if (temp->data == key) {
        printf("Key element is present in the BST\n");
        return;
    }

    if (key < temp->data)
        search(temp->left, key);
    else
        search(temp->right, key);
}

int main() {
    int ch, key,no;
    printf("\n~BST MENU~");
    printf("\n1.Insert into BST\n2.BST Traversals\n3.Search in BST\n4.Delete from BST\n5.Exit");
    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("enter no of nodes");
            scanf("%d",&no);
            for (int i = 0;i < no;i++) {
                 insertNode();
                  }
            
            break;
        case 2:
            if (root == NULL)
                printf("\nTree Is Not Created\n");
            else {
                printf("\nThe Preorder display : ");
                preorder(root);
                printf("\nThe Inorder display : ");
                inorder(root);
                printf("\nThe Postorder display : ");
                postorder(root);
            }
            break;
        case 3:
            if (root == NULL)
                printf("\nTree Is Not Created\n");
            else {
                printf("Enter the key to search: ");
                scanf("%d", &key);
                search(root, key);
            }
            break;
        case 4:
            if (root == NULL)
                printf("\nTree Is Not Created\n");
            else {
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node with key %d deleted\n", key);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}