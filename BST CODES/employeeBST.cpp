#include <iostream>
using namespace std;

struct Node {
    int id;
    int salary;
    Node *left, *right;
};

// Create a new node
Node* newNode(int id, int salary) {
    Node* p = new Node;
    p->id = id;
    p->salary = salary;
    p->left = p->right = NULL;
    return p;
}

// ---------------- INSERT EMPLOYEE ----------------
Node* insert(Node* root, int id, int salary) {
    if (root == NULL)
        return newNode(id, salary);

    if (id < root->id)
        root->left = insert(root->left, id, salary);
    else if (id > root->id)
        root->right = insert(root->right, id, salary);
    else
        cout << "Employee ID already exists!\n";

    return root;
}

// ---------------- SEARCH EMPLOYEE ----------------
Node* search(Node* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// ---------------- FIND MIN SALARY ----------------
int findMinSalary(Node* root) {
    if (root == NULL) return -1;
    while (root->left != NULL)
        root = root->left;
    return root->salary;
}

// ---------------- FIND MAX SALARY ----------------
int findMaxSalary(Node* root) {
    if (root == NULL) return -1;
    while (root->right != NULL)
        root = root->right;
    return root->salary;
}

// ---------------- DISPLAY ASCENDING ----------------
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->id << " (Salary: " << root->salary << ")\n";
    inorder(root->right);
}

// ---------------- DISPLAY DESCENDING ----------------
void descending(Node* root) {
    if (root == NULL) return;
    descending(root->right);
    cout << root->id << " (Salary: " << root->salary << ")\n";
    descending(root->left);
}

// ---------------- HEIGHT OF BST ----------------
int height(Node* root) {
    if (root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
        return 1 + lh;
    else
        return 1 + rh;
}

// ---------------- COUNT INTERNAL (NON-LEAF) NODES ----------------
int countInternal(Node* root) {
    if (root == NULL) return 0;

    // leaf node → not internal
    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + countInternal(root->left) + countInternal(root->right);
}

// ---------------- MAIN MENU ----------------
int main() {
    Node* root = NULL;
    int choice, id, salary;

    while (true) {
        cout << "\n--- Employee Data Management (BST) ---\n";
        cout << "1. Insert Employee Data\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Find Employee with Min & Max Salary\n";
        cout << "4. Display Employees (ASC & DESC)\n";
        cout << "5. Height & Internal Nodes\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Salary: ";
            cin >> salary;
            root = insert(root, id, salary);
            break;

        case 2:
            cout << "Enter Employee ID to Search: ";
            cin >> id;
            if (search(root, id))
                cout << "FOUND: Salary = " << search(root, id)->salary << endl;
            else
                cout << "Employee NOT found!\n";
            break;

        case 3:
            cout << "Minimum Salary: " << findMinSalary(root) << endl;
            cout << "Maximum Salary: " << findMaxSalary(root) << endl;
            break;

        case 4:
            cout << "\nAscending Order:\n";
            inorder(root);
            cout << "\nDescending Order:\n";
            descending(root);
            break;

        case 5:
            cout << "Height of BST: " << height(root) << endl;
            cout << "Internal Nodes: " << countInternal(root) << endl;
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
