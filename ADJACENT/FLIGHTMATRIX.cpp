#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string city[20];
    cout << "Enter city names:\n";
    for (int i = 0; i < n; i++)
        cin >> city[i];

    int adj[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int r;
    cout << "Enter number of flights: ";
    cin >> r;

    cout << "Enter flights (city1_index city2_index cost):\n";
    for (int i = 0; i < r; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        adj[a][b] = cost;
        adj[b][a] = cost;   // undirected flight path
    }

    int ch;
    while (1) {
        cout << "\n--- MATRIX MENU ---\n";
        cout << "1. Check direct flight\n";
        cout << "2. Print adjacency matrix\n";
        cout << "3. Exit\n";
        cin >> ch;

        if (ch == 1) {
            int a, b;
            cout << "Enter cities: ";
            cin >> a >> b;

            if (adj[a][b] != 0)
                cout << "Flight exists. Cost = " << adj[a][b] << endl;
            else
                cout << "No direct flight.\n";
        }
        else if (ch == 2) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << adj[i][j] << " ";
                cout << endl;
            }
        }
        else break;
    }
}
