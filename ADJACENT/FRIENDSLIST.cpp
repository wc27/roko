#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of users: ";
    cin >> n;

    string user[20];
    cout << "Enter user names:\n";
    for (int i = 0; i < n; i++)
        cin >> user[i];

    int adjList[20][20];
    int size[20] = {0};

    int f;
    cout << "Enter number of friendships: ";
    cin >> f;

    cout << "Enter friendships (A B):\n";
    for (int i = 0; i < f; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a][size[a]++] = b;
        adjList[b][size[b]++] = a;
    }

    int choice;
    while (true) {
        cout << "\n--- LIST MENU ---\n";
        cout << "1. Check if two users are friends\n";
        cout << "2. Display all friends of a user\n";
        cout << "3. Print adjacency list\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;

            bool found = false;
            for (int i = 0; i < size[a]; i++)
                if (adjList[a][i] == b) found = true;

            if (found)
                cout << user[a] << " and " << user[b] << " ARE friends.\n";
            else
                cout << user[a] << " and " << user[b] << " are NOT friends.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Friends of " << user[a] << ":\n";
            for (int i = 0; i < size[a]; i++)
                cout << " - " << user[adjList[a][i]] << endl;
        }

        else if (choice == 3) {
            cout << "\nAdjacency List:\n";
            for (int i = 0; i < n; i++) {
                cout << i << ": ";
                for (int j = 0; j < size[i]; j++)
                    cout << adjList[i][j] << " ";
                cout << endl;
            }
        }

        else break;
    }
}
