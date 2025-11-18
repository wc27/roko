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

    int adjList[20][20];
    int dist[20][20];
    int size[20] = {0};

    int roads;
    cout << "Enter number of roads: ";
    cin >> roads;

    cout << "Enter roads (A B distance):\n";
    for (int i = 0; i < roads; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        adjList[a][size[a]] = b;
        dist[a][size[a]] = d;
        size[a]++;

        adjList[b][size[b]] = a;
        dist[b][size[b]] = d;
        size[b]++;
    }

    int choice;
    while (true) {
        cout << "\n--- LIST MENU ---\n";
        cout << "1. Check direct road\n";
        cout << "2. Display roads from an intersection\n";
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
                cout << inter[a] << " and " << inter[b] << " ARE connected.\n";
            else
                cout << inter[a] << " and " << inter[b] << " are NOT connected.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Roads from " << inter[a] << ":\n";
            for (int i = 0; i < size[a]; i++)
                cout << " - " << inter[adjList[a][i]]
                     << " (Distance " << dist[a][i] << ")\n";
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
