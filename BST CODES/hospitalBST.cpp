#include <iostream>
using namespace std;

struct Node {
    int id;
    string name;
    Node *left, *right;
};

// Create a new node
Node* newNode(int id, string name) {
    Node* p = new Node;
    p->id = id;
    p->name = name;
    p->left = p->right = NULL;
    return p;
}

// Insert record into BST
Node* insert(Node* root, int id, string name) {
    if (root == NULL)
        return newNode(id, name);

    if (id < root->id)
        root->left = insert(root->left, id, name);
    else if (id > root->id)
        root->right = insert(root->right, id, name);
    else
        cout << "Patient ID already exists!\n";

    return root;
}

// Search a patient
Node* search(Node* root, int id) {
    if (root == NULL) return NULL;
    if (root->id == id) return root;

    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Inorder (sorted order)
void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->id << "  " << root->name << endl;
    inorder(root->right);
}

// Find Minimum ID
int minID(Node* root) {
    if (root == NULL) return -1;

    while (root->left != NULL)
        root = root->left;

    return root->id;
}

// Find Maximum ID
int maxID(Node* root) {
    if (root == NULL) return -1;

    while (root->right != NULL)
        root = root->right;

    return root->id;
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

// Height of tree
int height(Node* root) {
    if (root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}

int main() {
    Node* root = NULL;

    int choice, id;
    string name;

    while (true) {
        cout << "\n--- Patient Record System (BST) ---\n";
        cout << "1. Insert Patient\n";
        cout << "2. Search Patient by ID\n";
        cout << "3. Display All Patients (Sorted)\n";
        cout << "4. Find Min & Max ID\n";
        cout << "5. Node Count, Leaf Count & Height\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Patient Name: ";
            cin >> name;
            root = insert(root, id, name);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            if (search(root, id))
                cout << "Found: " << search(root, id)->name << endl;
            else
                cout << "Patient NOT found!\n";
            break;

        case 3:
            cout << "\nPatients in Sorted Order:\n";
            inorder(root);
            break;

        case 4:
            cout << "Minimum ID: " << minID(root) << endl;
            cout << "Maximum ID: " << maxID(root) << endl;
            break;

        case 5:
            cout << "Total Nodes: " << countNodes(root) << endl;
            cout << "Leaf Nodes: " << countLeaf(root) << endl;
            cout << "Height: " << height(root) << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
