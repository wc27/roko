#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

// Tree node
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(char ch) {
    Node* n = new Node;
    n->data = ch;
    n->left = n->right = NULL;
    return n;
}

// Check operator
bool isOperator(char ch) {
    return (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

// ===================================
// Construct Expression Tree from POSTFIX
// ===================================
Node* constructFromPostfix(char postfix[]) {
    stack<Node*> st;
    int len = strlen(postfix);

    // Scan left to right
    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (!isOperator(ch)) {
            st.push(createNode(ch));
        } else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();

            Node* newNode = createNode(ch);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }
    return st.top();
}


// ===================================
// RECURSIVE TRAVERSALS
// ===================================
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// ===================================
// NON-RECURSIVE TRAVERSALS
// ===================================

// Inorder: Left, Root, Right
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

// Preorder: Root, Left, Right
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

// Postorder: Left, Right, Root
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


// ===================================
// MIRROR TREE (Swap Left & Right)
// ===================================
void mirror(Node* root) {
    if (!root) return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}


// ===================================
// MENU DRIVEN PROGRAM
// ===================================
int main() {
    Node* root = NULL;
    char postfix[50];
    int choice;

    while (true) {
        cout << "\n===== POSTFIX EXPRESSION TREE MENU =====\n";
        cout << "1. Create Expression Tree (Postfix)\n";
        cout << "2. Recursive Traversals\n";
        cout << "3. Non-Recursive Traversals\n";
        cout << "4. Mirror the Tree (Swap Left & Right)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter postfix expression: ";
            cin >> postfix;
            root = constructFromPostfix(postfix);
            cout << "Expression tree created successfully.\n";
        }

        else if (choice == 2) {
            if (!root) cout << "Tree not created.\n";
            else {
                cout << "Inorder (recursive): "; inorder(root); cout << endl;
                cout << "Preorder (recursive): "; preorder(root); cout << endl;
                cout << "Postorder (recursive): "; postorder(root); cout << endl;
            }
        }

        else if (choice == 3) {
            if (!root) cout << "Tree not created.\n";
            else {
                cout << "Inorder (non-rec): "; inorderNonRec(root); cout << endl;
                cout << "Preorder (non-rec): "; preorderNonRec(root); cout << endl;
                cout << "Postorder (non-rec): "; postorderNonRec(root); cout << endl;
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
