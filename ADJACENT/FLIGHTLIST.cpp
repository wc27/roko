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

    int listCity[20][20];      // neighbours
    int listCost[20][20];      // weights
    int size[20];              // number of neighbours

    // initialize sizes
    for (int i = 0; i < n; i++)
        size[i] = 0;

    int r;
    cout << "Enter number of flights: ";
    cin >> r;

    cout << "Enter flights (city1 city2 cost):\n";
    for (int i = 0; i < r; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;

        listCity[a][size[a]] = b;
        listCost[a][size[a]] = cost;
        size[a]++;

        listCity[b][size[b]] = a;
        listCost[b][size[b]] = cost;
        size[b]++;
    }

    int ch;
    while (true) {
        cout << "\n--- LIST MENU ---\n";
        cout << "1. Check direct flight\n";
        cout << "2. Print adjacency list\n";
        cout << "3. Exit\n";
        cin >> ch;

        if (ch == 1) {
            int a, b;
            cout << "Enter city indexes: ";
            cin >> a >> b;

            bool found = false;
            for (int i = 0; i < size[a]; i++) {
                if (listCity[a][i] == b) {
                    cout << "Flight exists. Cost = " << listCost[a][i] << endl;
                    found = true;
                }
            }
            if (!found) cout << "No direct flight.\n";
        }

        else if (ch == 2) {
            for (int i = 0; i < n; i++) {
                cout << city[i] << ": ";
                for (int j = 0; j < size[i]; j++) {
                    cout << "(" << city[listCity[i][j]]
                         << ", cost=" << listCost[i][j] << ") ";
                }
                cout << endl;
            }
        }

        else break;
    }

    return 0;
}
