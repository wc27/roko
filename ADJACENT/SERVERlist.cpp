#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of servers: ";
    cin >> n;

    string server[20];
    cout << "Enter server names:\n";
    for (int i = 0; i < n; i++) cin >> server[i];

    int adjList[20][20];
    int latency[20][20];
    int size[20] = {0};

    int cables;
    cout << "Enter number of cables: ";
    cin >> cables;

    cout << "Enter cables with weight:\n";
    for (int i = 0; i < cables; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        adjList[a][size[a]] = b;
        latency[a][size[a]] = w;
        size[a]++;

        adjList[b][size[b]] = a;
        latency[b][size[b]] = w;
        size[b]++;
    }

    int choice;
    while (true) {
        cout << "\n--- LIST MENU ---\n";
        cout << "1. Check direct connection\n";
        cout << "2. Display all connections from a server\n";
        cout << "3. Print adjacency list\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cin >> a >> b;

            bool found = false;
            for (int i = 0; i < size[a]; i++) {
                if (adjList[a][i] == b) found = true;
            }

            if (found) cout << server[a] << " and " << server[b] << " ARE connected.\n";
            else cout << server[a] << " and " << server[b] << " are NOT connected.\n";
        }

        else if (choice == 2) {
            int a;
            cin >> a;

            cout << "Connections from " << server[a] << ":\n";
            for (int i = 0; i < size[a]; i++)
                cout << " - " << server[adjList[a][i]]
                     << " \n";
        }

        else if (choice == 3) {
            cout << "\nAdjacency List:\n";
            for (int i = 0; i < n; i++) {
                cout << i << ": ";
                for (int j = 0; j < size[i]; j++)
                  cout << "(" << adjList[i][j] << ", " << latency[i][j] << ") ";

                cout << endl;
            }
        }

        else break;
    }
}
