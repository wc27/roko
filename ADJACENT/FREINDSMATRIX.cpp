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

    int adj[20][20] = {0};

    int f;
    cout << "Enter number of friendships: ";
    cin >> f;

    cout << "Enter friendships (A B):\n";
    for (int i = 0; i < f; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    int choice;
    while (true) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check if two users are friends\n";
        cout << "2. Display all friends of a user\n";
        cout << "3. Print matrix\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;
            if (adj[a][b] == 1)
                cout << user[a] << " and " << user[b] << " ARE friends.\n";
            else
                cout << user[a] << " and " << user[b] << " are NOT friends.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Friends of " << user[a] << ":\n";
            for (int i = 0; i < n; i++)
                if (adj[a][i] == 1)
                    cout << " - " << user[i] << endl;
        }

        else if (choice == 3) {
            cout << "\nAdjacency Matrix:\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << adj[i][j] << " ";
                cout << endl;
            }
        }

        else break;
    }
}
