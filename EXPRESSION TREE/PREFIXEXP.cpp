#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

// Expression Tree Node
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(char ch) {
    Node* n = new Node;
    n->data = ch;
    n->left = n->right = NULL;
    return n;
}

// Check if character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// ===============================
// Construct Expression Tree using Prefix Expression
// ===============================
Node* constructFromPrefix(char prefix[]) {
    stack<Node*> st;
    int len = strlen(prefix);

    // Scan from right to left
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If operand → push node
        if (!isOperator(ch)) {
            st.push(createNode(ch));
        }
        else {
            // Operator → pop two nodes
            Node* left = st.top(); st.pop();
            Node* right = st.top(); st.pop();

            Node* newNode = createNode(ch);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();
}


// ===============================
// RECURSIVE TRAVERSALS
// ===============================

void inorderRec(Node* root) {
    if (root == NULL) return;
    inorderRec(root->left);
    cout << root->data << " ";
    inorderRec(root->right);
}

void preorderRec(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void postorderRec(Node* root) {
    if (root == NULL) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->data << " ";
}


// ===============================
// NON-RECURSIVE TRAVERSALS
// ===============================

void inorderNonRec(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorderNonRec(Node* root) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        cout << curr->data << " ";

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

void postorderNonRec(Node* root) {
    if (!root) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top(); st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}


// ===============================
// MIRROR TREE (SWAP LEFT & RIGHT)
// ===============================
void mirror(Node* root) {
    if (root == NULL) return;

    // Swap children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recurse
    mirror(root->left);
    mirror(root->right);
}


// ===============================
// MAIN MENU
// ===============================
int main() {
    Node* root = NULL;
    char prefix[50];
    int choice;

    while (true) {
        cout << "\n===== EXPRESSION TREE MENU =====\n";
        cout << "1. Create Expression Tree (Prefix)\n";
        cout << "2. Recursive Traversals\n";
        cout << "3. Non-Recursive Traversals\n";
        cout << "4. Mirror the Tree (Swap Left & Right)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter prefix expression: ";
            cin >> prefix;
            root = constructFromPrefix(prefix);
            cout << "Expression tree created successfully.\n";
        }

        else if (choice == 2) {
            if (!root) cout << "Tree not created.\n";
            else {
                cout << "Inorder (Recursive): "; inorderRec(root); cout << endl;
                cout << "Preorder (Recursive): "; preorderRec(root); cout << endl;
                cout << "Postorder (Recursive): "; postorderRec(root); cout << endl;
            }
        }

        else if (choice == 3) {
            if (!root) cout << "Tree not created.\n";
            else {
                cout << "Inorder (Non-Recursive): "; inorderNonRec(root); cout << endl;
                cout << "Preorder (Non-Recursive): "; preorderNonRec(root); cout << endl;
                cout << "Postorder (Non-Recursive): "; postorderNonRec(root); cout << endl;
            }
        }

        else if (choice == 4) {
            if (!root) cout << "Tree not created.\n";
            else {
                mirror(root);
                cout << "Tree mirrored successfully.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
