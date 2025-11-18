#include <iostream>
using namespace std;

struct Node {
    int bookID;
    Node *left, *right;
};

// Create a new node
Node* newNode(int id) {
    Node* p = new Node;
    p->bookID = id;
    p->left = p->right = NULL;
    return p;
}

// ---------------- INSERT BOOK ----------------
Node* insert(Node* root, int id) {
    if (root == NULL)
        return newNode(id);

    if (id < root->bookID)
        root->left = insert(root->left, id);
    else if (id > root->bookID)
        root->right = insert(root->right, id);
    else
        cout << "Book ID already exists!\n";

    return root;
}

// --------------- FIND MIN BOOK ID ---------------
int findMin(Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL)
        root = root->left;

    return root->bookID;
}

// --------------- FIND MAX BOOK ID ---------------
int findMax(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->bookID;
}

// --------------- INORDER DISPLAY (Sorted) ---------------
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->bookID << " ";
    inorder(root->right);
}

// --------------- DELETE BOOK ---------------
Node* findMinNode(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->bookID)
        root->left = deleteNode(root->left, id);
    else if (id > root->bookID)
        root->right = deleteNode(root->right, id);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: One child (left)
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMinNode(root->right);
            root->bookID = temp->bookID;
            root->right = deleteNode(root->right, temp->bookID);
        }
    }
    return root;
}

// --------------- COUNT TOTAL BOOKS ---------------
int countBooks(Node* root) {
    if (root == NULL) return 0;
    return 1 + countBooks(root->left) + countBooks(root->right);
}

// ----------------------- MAIN MENU -----------------------
int main() {
    Node* root = NULL;
    int choice, id;

    while (true) {
        cout << "\n--- Library Book Catalog (BST) ---\n";
        cout << "1. Insert a New Book\n";
        cout << "2. Delete a Book\n";
        cout << "3. Find Smallest & Largest Book ID\n";
        cout << "4. Display All Books (Sorted)\n";
        cout << "5. Count Total Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Book ID to insert: ";
            cin >> id;
            root = insert(root, id);
            break;

        case 2:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            root = deleteNode(root, id);
            break;

        case 3:
            cout << "Smallest Book ID: " << findMin(root) << endl;
            cout << "Largest Book ID: " << findMax(root) << endl;
            break;

        case 4:
            cout << "Books in Sorted Order: ";
            inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Total Books in Catalog: " << countBooks(root) << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}
