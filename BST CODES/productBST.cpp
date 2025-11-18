#include <iostream>
using namespace std;

struct Node {
    int code;       // product code
    int qty;        // quantity
    Node *left, *right;
};

// Create new node
Node* newNode(int code, int qty) {
    Node* p = new Node;
    p->code = code;
    p->qty = qty;
    p->left = p->right = NULL;
    return p;
}

// -------------------- INSERT PRODUCT --------------------
Node* insert(Node* root, int code, int qty) {
    if (root == NULL)
        return newNode(code, qty);

    if (code < root->code)
        root->left = insert(root->left, code, qty);
    else if (code > root->code)
        root->right = insert(root->right, code, qty);
    else
        cout << "Product code already exists!\n";

    return root;
}

// -------------------- SEARCH PRODUCT --------------------
Node* search(Node* root, int code) {
    if (root == NULL || root->code == code)
        return root;

    if (code < root->code)
        return search(root->left, code);
    else
        return search(root->right, code);
}

// -------------------- FIND MIN CODE --------------------
int findMin(Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL)
        root = root->left;

    return root->code;
}

// -------------------- FIND MAX CODE --------------------
int findMax(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->code;
}

// -------------------- DELETE PRODUCT --------------------
Node* findMinNode(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int code) {
    if (root == NULL)
        return root;

    if (code < root->code)
        root->left = deleteNode(root->left, code);

    else if (code > root->code)
        root->right = deleteNode(root->right, code);

    else {
        // Case 1: Leaf node
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
            root->code = temp->code;
            root->qty = temp->qty;
            root->right = deleteNode(root->right, temp->code);
        }
    }
    return root;
}

// -------------------- ASCENDING DISPLAY --------------------
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << "Code: " << root->code << ", Qty: " << root->qty << endl;
    inorder(root->right);
}

// -------------------- DESCENDING DISPLAY --------------------
void descending(Node* root) {
    if (root == NULL) return;
    descending(root->right);
    cout << "Code: " << root->code << ", Qty: " << root->qty << endl;
    descending(root->left);
}

// -------------------- MAIN MENU --------------------
int main() {
    Node* root = NULL;
    int choice, code, qty;

    while (true) {
        cout << "\n--- Store Product Inventory (BST) ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Delete Product\n";
        cout << "3. Search Product\n";
        cout << "4. Find Min & Max Product Code\n";
        cout << "5. Display Products (Ascending & Descending)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter product code: ";
            cin >> code;
            cout << "Enter quantity: ";
            cin >> qty;
            root = insert(root, code, qty);
            break;

        case 2:
            cout << "Enter product code to delete: ";
            cin >> code;
            root = deleteNode(root, code);
            break;

        case 3:
            cout << "Enter product code to search: ";
            cin >> code;
            if (search(root, code))
                cout << "FOUND: Qty = " << search(root, code)->qty << endl;
            else
                cout << "Product NOT found!\n";
            break;

        case 4:
            cout << "Minimum Product Code: " << findMin(root) << endl;
            cout << "Maximum Product Code: " << findMax(root) << endl;
            break;

        case 5:
            cout << "\nAscending Order:\n";
            inorder(root);
            cout << "\nDescending Order:\n";
            descending(root);
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid option!\n";
        }
    }
}
