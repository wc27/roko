#include <iostream>
using namespace std;

struct Node {
    int roll;
    string name;
    Node *left, *right;
};

// Create new node
Node* newNode(int roll, string name) {
    Node* p = new Node;
    p->roll = roll;
    p->name = name;
    p->left = p->right = NULL;
    return p;
}

// Insert student
Node* insert(Node* root, int roll, string name) {
    if (root == NULL)
        return newNode(roll, name);

    if (roll < root->roll)
        root->left = insert(root->left, roll, name);
    else if (roll > root->roll)
        root->right = insert(root->right, roll, name);
    else
        cout << "Roll number already exists!\n";

    return root;
}

// Search student
Node* search(Node* root, int roll) {
    if (root == NULL || root->roll == roll)
        return root;

    if (roll < root->roll)
        return search(root->left, roll);
    else
        return search(root->right, roll);
}

// Find minimum node
Node* findMinNode(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete student
Node* deleteNode(Node* root, int roll) {
    if (root == NULL)
        return root;

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMinNode(root->right);
            root->roll = temp->roll;
            root->name = temp->name;
            root->right = deleteNode(root->right, temp->roll);
        }
    }
    return root;
}

// Display in ascending order
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->roll << "  " << root->name << endl;
    inorder(root->right);
}

// Display in descending order
void descending(Node* root) {
    if (root == NULL)
        return;
    descending(root->right);
    cout << root->roll << "  " << root->name << endl;
    descending(root->left);
}

// Count nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaf(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// HEIGHT using simple IF–ELSE instead of ternary operator
int height(Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
        return 1 + lh;
    else
        return 1 + rh;
}

// MAIN MENU
int main() {
    Node* root = NULL;
    int choice, roll;
    string name;

    while (true) {
        cout << "\n--- Student Record BST System ---\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Delete Student Record\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Display in Ascending Order\n";
        cout << "5. Display in Descending Order\n";
        cout << "6. Display Height and Total Nodes\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin >> name;
            root = insert(root, roll, name);
            break;

        case 2:
            cout << "Enter Roll Number to Delete: ";
            cin >> roll;
            root = deleteNode(root, roll);
            break;

        case 3:
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            if (search(root, roll))
                cout << "FOUND: " << search(root, roll)->name << endl;
            else
                cout << "Student NOT found!\n";
            break;

        case 4:
            cout << "\nAscending Order:\n";
            inorder(root);
            break;

        case 5:
            cout << "\nDescending Order:\n";
            descending(root);
            break;

        case 6:
            cout << "Total Nodes: " << countNodes(root) << endl;
            cout << "Height: " << height(root) << endl;
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
