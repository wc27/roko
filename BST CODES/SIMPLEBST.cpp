#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = NULL;
    return n;
}

// Insert into BST
Node* insertNode(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

// Find minimum value in BST (leftmost node)
int findMin(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty.\n";
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Search a value in BST
bool search(Node* root, int value) {
    if (root == NULL) return false;

    if (value == root->data) return true;
    else if (value < root->data) return search(root->left, value);
    else return search(root->right, value);
}

// Height of BST = longest path from root
int height(Node* root) {
    if (root == NULL) return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
}

// Print in ascending order (Inorder)
void printAscending(Node* root) {
    if (root == NULL) return;
    printAscending(root->left);
    cout << root->data << " ";
    printAscending(root->right);
}

// Print in descending order (Reverse Inorder)
void printDescending(Node* root) {
    if (root == NULL) return;
    printDescending(root->right);
    cout << root->data << " ";
    printDescending(root->left);
}


// =========================
// MENU DRIVEN PROGRAM
// =========================
int main() {
    Node* root = NULL;
    int choice, value;

    while (true) {
        cout << "\n===== BINARY SEARCH TREE MENU =====\n";
        cout << "1. Insert Node\n";
        cout << "2. Longest Path from Root (Height)\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Search a Value\n";
        cout << "5. Print Ascending Order\n";
        cout << "6. Print Descending Order\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "Node inserted.\n";
        }

        else if (choice == 2) {
            cout << "Longest path from root (height): " << height(root) << endl;
        }

        else if (choice == 3) {
            value = findMin(root);
            if (value != -1)
                cout << "Minimum value in BST: " << value << endl;
        }

        else if (choice == 4) {
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Value FOUND in BST.\n";
            else
                cout << "Value NOT FOUND.\n";
        }

        else if (choice == 5) {
            cout << "Ascending order: ";
            printAscending(root);
            cout << endl;
        }

        else if (choice == 6) {
            cout << "Descending order: ";
            printDescending(root);
            cout << endl;
        }

        else if (choice == 7) {
            cout << "Exiting program...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}




/*(choice == 1) {
    int n;
    cout << "How many values? ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insertNode(root, value);
    }
}*/
