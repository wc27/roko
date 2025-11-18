#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of airlines: ";
    cin >> n;

    string airline[20];
    cout << "Enter airline names:\n";
    for (int i = 0; i < n; i++)
        cin >> airline[i];

    int adj[20][20] = {0};

    int p;
    cout << "Enter number of partnerships: ";
    cin >> p;

    cout << "Enter partnerships (A B strength):\n";
    for (int i = 0; i < p; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a][b] = w;
        adj[b][a] = w;
    }

    int choice;
    while (true) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check partnership\n";
        cout << "2. Display all connected airlines\n";
        cout << "3. Print adjacency matrix\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b] != 0)
                cout << airline[a] << " and " << airline[b]
                     << " HAVE a partnership (Strength = " << adj[a][b] << ")\n";
            else
                cout << airline[a] << " and " << airline[b] << " have NO partnership.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Airlines connected to " << airline[a] << ":\n";
            for (int j = 0; j < n; j++)
                if (adj[a][j] != 0)
                    cout << " - " << airline[j] << " (Strength " << adj[a][j] << ")\n";
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
