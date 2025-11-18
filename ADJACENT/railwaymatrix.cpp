#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string city[20];
    cout << "Enter city names:\n";
    for (int i = 0; i < n; i++) cin >> city[i];

    int adj[20][20] = {0};

    int r;
    cout << "Enter number of routes: ";
    cin >> r;

    cout << "Enter routes (A B):\n";
    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    int choice;
    while (true) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check direct connection\n";
        cout << "2. Display all connections from a city\n";
        cout << "3. Print matrix\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;
            if (adj[a][b]) cout << city[a] << " and " << city[b] << " ARE connected.\n";
            else cout << city[a] << " and " << city[b] << " are NOT connected.\n";
        }
        else if (choice == 2) {
            int a;
            cin >> a;
            cout << "Connections from " << city[a] << ":\n";
            for (int j = 0; j < n; j++)
                if (adj[a][j]) cout << " - " << city[j] << endl;
        }
        else if (choice == 3) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << adj[i][j] << " ";
                cout << endl;
            }
        }
        else break;
    }
}
