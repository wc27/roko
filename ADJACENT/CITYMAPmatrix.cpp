#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of intersections: ";
    cin >> n;

    string inter[20];
    cout << "Enter intersection names:\n";
    for (int i = 0; i < n; i++)
        cin >> inter[i];

    int adj[20][20] = {0};

    int roads;
    cout << "Enter number of roads: ";
    cin >> roads;

    cout << "Enter roads (A B distance):\n";
    for (int i = 0; i < roads; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a][b] = d;
        adj[b][a] = d;
    }

    int choice;
    while (true) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check direct road\n";
        cout << "2. Display roads from an intersection\n";
        cout << "3. Print matrix\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;
            if (adj[a][b] != 0)
                cout << inter[a] << " and " << inter[b]
                     << " ARE connected (Distance = " << adj[a][b] << ")\n";
            else
                cout << inter[a] << " and " << inter[b] << " are NOT connected.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Roads from " << inter[a] << ":\n";
            for (int j = 0; j < n; j++) {
                if (adj[a][j] != 0)
                    cout << " - " << inter[j] << " (Distance " << adj[a][j] << ")\n";
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
