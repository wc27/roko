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
    int listC[20][20], listCost[20][20], size[20];

    // Initialize matrix + list sizes
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    int r;
    cout << "Enter number of flights: ";
    cin >> r;

    cout << "Enter flights (A B cost):\n";
    for (int i = 0; i < r; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        adj[a][b] = adj[b][a] = cost;

        listC[a][size[a]] = b;
        listCost[a][size[a]] = cost;
        size[a]++;

        listC[b][size[b]] = a;
        listCost[b][size[b]] = cost;
        size[b]++;
    }

    int ch;
    while (true) {
        cout << "\n--- GRAPH MENU ---\n";
        cout << "1. Check flight\n";
        cout << "2. Print matrix\n";
        cout << "3. Print list\n";
        cout << "4. Exit\n";
        cin >> ch;

        if (ch == 1) {
            int a, b;
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

        else if (ch == 3) {
            for (int i = 0; i < n; i++) {
                cout << city[i] << ": ";
                for (int j = 0; j < size[i]; j++)
                    cout << "(" << city[listC[i][j]] << ", " << listCost[i][j] << ") ";
                cout << endl;
            }
        }

        else break;
    }

    return 0;
}
