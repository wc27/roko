#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of servers: ";
    cin >> n;

    string server[20];
    cout << "Enter server names:\n";
    for (int i = 0; i < n; i++) cin >> server[i];

    int adj[20][20] = {0};

    int cables;
    cout << "Enter number of cables: ";
    cin >> cables;

    cout << "Enter cables with weight:\n";
    for (int i = 0; i < cables; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
    }

    int choice;
    while (true) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check direct connection\n";
        cout << "2. Display all connections from a server\n";
        cout << "3. Print matrix\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b] != 0)
                cout << server[a] << " and " << server[b]
                     << " ARE connected \n";
            else
                cout << server[a] << " and " << server[b] << " are NOT connected.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Connections from " << server[a] << ":\n";
            for (int j = 0; j < n; j++) {
                if (adj[a][j] != 0)
                    cout << " - " << server[j] << "\n";
            }
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
